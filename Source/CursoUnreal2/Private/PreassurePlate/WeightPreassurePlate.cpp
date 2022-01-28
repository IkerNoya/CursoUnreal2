// Copyright Iker Noya 2022.


#include "PreassurePlate/WeightPreassurePlate.h"

#include "CursoUnreal2/EscapeRoom/ItemSpawner.h"

void AWeightPreassurePlate::HandleDoor()
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

void AWeightPreassurePlate::HandleSpawner()
{
	if(ItemSpawner && IsMassEnoughToActivate())
	{
		ItemSpawner->SpawnItem();
	}
}

void AWeightPreassurePlate::BeginPlay()
{
	Super::BeginPlay();
	
	Door = Cast<ADoorBase>(ActorToActivate);
	ItemSpawner = Cast<AItemSpawner>(ActorToActivate);
	if(!Door)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't get door"));
	}
	if(!ItemSpawner)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't get Spawner"));
	}
}

void AWeightPreassurePlate::HandleInteraction()
{
	switch (TypeActor)
	{
	case ETypeActor::Door:
		HandleDoor();
		break;
	case ETypeActor::Spawner:
		HandleSpawner();
		break;
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
