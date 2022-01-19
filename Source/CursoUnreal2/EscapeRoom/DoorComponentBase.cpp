// Copyright Iker Noya 2022.


#include "DoorComponentBase.h"

#include "Components/AudioComponent.h"

// Sets default values for this component's properties
UDoorComponentBase::UDoorComponentBase()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}


// Called when the game starts
void UDoorComponentBase::BeginPlay()
{
	Super::BeginPlay();

	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw=InitialYaw;
	TargetOpenedDoorYaw = InitialYaw + OpenedAngle;
	
	FindAudioComponent();
	
}

void UDoorComponentBase::FindAudioComponent()
{
	DoorSound = GetOwner()->FindComponentByClass<UAudioComponent>();
	if(!DoorSound)
	{
		UE_LOG(LogTemp, Error, TEXT("Couln't find audio component in actor: %s"), *GetOwner()->GetName());
	}
}

void UDoorComponentBase::OpenDoor()
{
	
}

void UDoorComponentBase::CloseDoor()
{
	
}


