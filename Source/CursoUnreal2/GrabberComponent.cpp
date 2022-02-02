// Copyright Iker Noya 2022.


#include "GrabberComponent.h"

#include "MainPlayer.h"
#include "GameFramework/GameSession.h"

#define OUT // No hace nada, le agrega legibilidad
#define ECC_Connectable       ECC_GameTraceChannel2
#define ECC_Interactable      ECC_GameTraceChannel1

UGrabberComponent::UGrabberComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UGrabberComponent::BeginPlay()
{
	Super::BeginPlay();
	AMainPlayer* Player = Cast<AMainPlayer>(GetOwner());
	if(Player)
	{
		TargetLocation = Player->TargetLocation;
	}
	FindPhysicsHandle();
}

void UGrabberComponent::FindPhysicsHandle()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if(!PhysicsHandle)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't find physics handle component in Pawn: %s"), *GetOwner()->GetName())
	}
}

FHitResult UGrabberComponent::GetFirstPhysicsBodyInReach()
{
	FHitResult Hit;
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(OUT  Hit, PlayerLocation, GetPlayerReach(), FCollisionObjectQueryParams(ECC_TO_BITFIELD(ECC_PhysicsBody) | ECC_TO_BITFIELD(ECC_Connectable) | ECC_TO_BITFIELD(ECC_Interactable)), TraceParams);
	
	return Hit;
}

FVector UGrabberComponent::GetPlayerReach() const
{
	return PlayerLocation + PlayerRotation.Vector() * Reach;
}

void UGrabberComponent::SetPlayerLocationAndRotation() 
{
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerLocation, OUT PlayerRotation);
}

void UGrabberComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	SetPlayerLocationAndRotation();
	if(PhysicsHandle && PhysicsHandle->GetGrabbedComponent() && TargetLocation)
	{
		PhysicsHandle->SetTargetLocationAndRotation(TargetLocation->GetComponentLocation(), TargetLocation->GetComponentRotation());
	}
}

void UGrabberComponent::Grab()
{
	FHitResult Hit = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* ComponentToGrab = Hit.GetComponent();
	AActor* Actor = Hit.GetActor();
	if(PhysicsHandle && ComponentToGrab && Actor && TargetLocation)
	{
		PhysicsHandle->GrabComponentAtLocationWithRotation(ComponentToGrab,NAME_None, TargetLocation->GetComponentLocation(), TargetLocation->GetComponentRotation());
		bIsObjectGrabbed=true;
	}
}

void UGrabberComponent::Drop()
{
	if(PhysicsHandle)
	{
		bIsObjectGrabbed=false;
		PhysicsHandle->ReleaseComponent();
	}
}

void UGrabberComponent::RotateObject(FRotator Value)
{
	if(TargetLocation)
	{
		TargetLocation->AddWorldRotation(Value);
	}
}

void UGrabberComponent::Throw(FVector Direction)
{
	if(PhysicsHandle && PhysicsHandle->GetGrabbedComponent())
	{
		UPrimitiveComponent* GrabbedComponent = PhysicsHandle->GrabbedComponent;
		Drop();
		GrabbedComponent->WakeRigidBody();
		GrabbedComponent->AddImpulse(Direction * ThrowForce, NAME_None, true);
		GrabbedComponent=nullptr;
	}
}



