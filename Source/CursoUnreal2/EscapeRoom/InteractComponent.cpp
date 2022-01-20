// Copyright Iker Noya 2022.


#include "InteractComponent.h"

#include "Interactable.h"

// Sets default values for this component's properties
UInteractComponent::UInteractComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UInteractComponent::Interact()
{
	FHitResult Hit;
	FVector Location;
	FRotator Rotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT Location, OUT Rotation);
	FCollisionQueryParams TraceParams(FName(TEXT("")), false, GetOwner());
	if(GetWorld()->LineTraceSingleByObjectType(Hit, Location, Location + Rotation.Vector() * InteractDistance, FCollisionObjectQueryParams(ECollisionChannel::ECC_WorldStatic), TraceParams))
	{
		AActor* Actor = Hit.GetActor();
		if(Actor)
		{
			UInteractable* Interactable = Actor->FindComponentByClass<UInteractable>();
			if(Interactable)
			{
				Interactable->ActivateActor();
			}
			
		}
	}
}

