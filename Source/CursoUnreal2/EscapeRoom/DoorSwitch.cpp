// Copyright Iker Noya 2022.


#include "DoorSwitch.h"

void ADoorSwitch::BeginPlay()
{
	Super::BeginPlay();
}

void ADoorSwitch::HandleInteraction()
{
	for(int i = 0; i < ActorsToActivate.Num();i++)
	{
		if(ActorsToActivate[i])
		{
			ActorsToActivate[i]->ActivateActor();
		}
	}
}

