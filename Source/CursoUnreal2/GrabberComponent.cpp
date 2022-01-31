// Copyright Iker Noya 2022.


#include "GrabberComponent.h"

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
	if(PhysicsHandle && PhysicsHandle->GetGrabbedComponent())
	{
		PhysicsHandle->SetTargetLocation(GetPlayerReach());
	}
}

void UGrabberComponent::Grab()
{
	FHitResult Hit = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* ComponentToGrab = Hit.GetComponent();
	AActor* Actor = Hit.GetActor();
	if(PhysicsHandle && ComponentToGrab && Actor)
	{
		PhysicsHandle->GrabComponentAtLocationWithRotation(ComponentToGrab,NAME_None, GetPlayerReach(), Hit.GetActor()->GetActorRotation());
	}
}

void UGrabberComponent::Drop()
{
	if(PhysicsHandle)
	{
		PhysicsHandle->ReleaseComponent();
	}
}

