// Copyright Iker Noya 2022.


#include "PreassurePlate/WeightPreassurePlate.h"

void AWeightPreassurePlate::BeginPlay()
{
	Super::BeginPlay();
	
	Door = Cast<ADoorBase>(ActorToActivate);
	if(!Door)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't get door"));
	}
}

void AWeightPreassurePlate::HandleInteraction()
{
	if(Door && !bWasActive && IsMassEnoughToActivate())
	{
		Door->TryInteractWithDoor();
		bWasActive=true;
	}
	else if(Door && bWasActive && !IsMassEnoughToActivate())
	{
		Door->TryInteractWithDoor();
		bWasActive=false;
	}
}

bool AWeightPreassurePlate::IsMassEnoughToActivate()
{
	float Mass = 0.f;
	TArray<AActor*> ActorsOverlapping;
	TriggerBox->GetOverlappingActors(ActorsOverlapping);
	for(AActor* Actor : ActorsOverlapping)
	{
		if(IsValid(Actor))
		{
			UPrimitiveComponent* OtherComponent = Actor->FindComponentByClass<UPrimitiveComponent>();
			if(IsValid(OtherComponent))
			{
				Mass+=OtherComponent->GetMass();
			}
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Mass: %f | MassToActivate: %f"), Mass, MassToActivate);
	return Mass>=MassToActivate;
}
