// Copyright Iker Noya 2022.


#include "DoorSwitch.h"

void ADoorSwitch::BeginPlay()
{
	Super::BeginPlay();
	if(ActorToActivate)
	{
		DoorToActivate = Cast<ADoorBase>(ActorToActivate);
		if(!DoorToActivate)
		{
			UE_LOG(LogTemp, Error, TEXT("Couldn't cast %s To DoorBase"), *ActorToActivate->GetName())
		}
	}
}

void ADoorSwitch::HandleInteraction()
{
	Super::HandleInteraction();
	if(DoorToActivate)
	{
		DoorToActivate->TryInteractWithDoor();
	}
}

