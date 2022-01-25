// Copyright Iker Noya 2022.


#include "ItemSpawnerSwitch.h"


void AItemSpawnerSwitch::BeginPlay()
{
	Super::BeginPlay();
	if(ActorToActivate)
	{
		ItemSpawner = Cast<AItemSpawner>(ActorToActivate);
		if(!ItemSpawner)
		{
			UE_LOG(LogTemp, Error, TEXT("Couldn't find item spawner class in %s"), *ActorToActivate->GetName());
		}
	}
}

void AItemSpawnerSwitch::HandleInteraction()
{
	Super::HandleInteraction();
	if(ItemSpawner)
	{
		ItemSpawner->SpawnItem();
	}
}
