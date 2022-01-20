// Copyright Iker Noya 2022.


#include "Interactable.h"

// Sets default values for this component's properties
UInteractable::UInteractable()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UInteractable::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UInteractable::ActivateActor()
{
	UDoorComponentBase* Door = Actor->FindComponentByClass<UDoorComponentBase>();
	if(Door)
	{
		Door->ActivateDoor();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Door doesn't Exist"));
	}
}



