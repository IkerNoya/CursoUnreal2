// Copyright Iker Noya 2022.


#include "ItemSpawnerSwitch.h"


void AItemSpawnerSwitch::BeginPlay()
{
	Super::BeginPlay();
}

void AItemSpawnerSwitch::HandleInteraction()
{
	Super::HandleInteraction();
	for(int i = 0; i < ActorsToActivate.Num();i++)
	{
		if(ActorsToActivate[i])
		{
			ActorsToActivate[i]->ActivateActor();
		}
	}
}
