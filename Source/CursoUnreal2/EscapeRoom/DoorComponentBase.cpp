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

void UDoorComponentBase::OpenDoor(float DeltaTime)
{
	OpenDoorLogic(DeltaTime);
	if(DoorSound && !bOpenDoorSound)
	{
		DoorSound->Play();
		bOpenDoorSound=true;
		bCloseDoorSound=false;
	}
}

void UDoorComponentBase::CloseDoor(float DeltaTime)
{
	CloseDoorLogic(DeltaTime);
	if(DoorSound &&  !bCloseDoorSound)
	{
		DoorSound->Play();
		bCloseDoorSound=true;
		bOpenDoorSound=false;
	}
}

void UDoorComponentBase::OpenDoorLogic(float DeltaTime)
{
	CurrentYaw = FMath::Lerp(CurrentYaw, TargetOpenedDoorYaw, DeltaTime * OpeningSpeed);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}

void UDoorComponentBase::CloseDoorLogic(float DeltaTime)
{
	CurrentYaw = FMath::Lerp(CurrentYaw, InitialYaw, DeltaTime * OpeningSpeed);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}

void UDoorComponentBase::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if(bShouldOpenDoor)
	{
		OpenDoor(DeltaTime);
	}
	else
	{
		CloseDoor(DeltaTime);
	}
}


