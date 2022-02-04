// Copyright Iker Noya 2022.


#include "Quest/ObjectivePickup.h"


// Sets default values for this component's properties
UObjectivePickup::UObjectivePickup()
{

	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UObjectivePickup::BeginPlay()
{
	Super::BeginPlay();
	
}

void UObjectivePickup::OnPickup()
{
	IQuestInterface::OnPickup();
	if(!bItemAlreadyPickedUp)
	{
		//CompleteObjective
		bItemAlreadyPickedUp=true;
	}
}




