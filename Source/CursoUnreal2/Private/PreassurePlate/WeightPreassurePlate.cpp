// Copyright Iker Noya 2022.


#include "PreassurePlate/WeightPreassurePlate.h"



void AWeightPreassurePlate::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeightPreassurePlate::HandleInteraction()
{
	if(!bWasActive && IsMassEnoughToActivate())
	{
		for(int i = 0; i < ActorsToActivate.Num(); i++)
		{
			if(ActorsToActivate[i])
			{
				ActorsToActivate[i]->ActivateActor();
				bWasActive=true;
			}
		}
	}
	else if(bWasActive && !IsMassEnoughToActivate())
	{
		for(int i = 0; i < ActorsToActivate.Num(); i++)
		{
			if(ActorsToActivate[i])
			{
				ActorsToActivate[i]->ActivateActor();
				bWasActive=false;
			}
		}
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
