// Copyright Iker Noya 2022.


#include "Interactable.h"

UInteractable::UInteractable()
{

	PrimaryComponentTick.bCanEverTick = false;

}

void UInteractable::BeginDestroy()
{
	OnInteract.Clear();
	Super::BeginDestroy();
}

void UInteractable::ActivateActor()
{
	OnInteract.Broadcast();
}



