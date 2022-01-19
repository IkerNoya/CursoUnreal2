// Copyright Iker Noya 2022.


#include "GrabberComponent.h"

#define OUT // No hace nada, le agrega legibilidad

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
	GetWorld()->LineTraceSingleByObjectType(OUT  Hit, PlayerLocation, LineTraceEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParams);

	return Hit;

}


void UGrabberComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerLocation,OUT PlayerRotation);
	LineTraceEnd = PlayerLocation + PlayerRotation.Vector() * Reach;
	
	if(PhysicsHandle && PhysicsHandle->GetGrabbedComponent())
	{
		PhysicsHandle->SetTargetLocation(LineTraceEnd);
	}
}

void UGrabberComponent::Grab()
{
	FHitResult Hit = GetFirstPhysicsBodyInReach();
	UPrimitiveComponent* ComponentToGrab = Hit.GetComponent();
	if(PhysicsHandle && ComponentToGrab && Hit.GetActor())
	{
		PhysicsHandle->GrabComponentAtLocationWithRotation(ComponentToGrab,NAME_None, LineTraceEnd, PlayerRotation);
	}
}

void UGrabberComponent::Drop()
{
	if(PhysicsHandle)
	{
		PhysicsHandle->ReleaseComponent();
	}
}

