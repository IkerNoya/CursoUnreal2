// Copyright Iker Noya 2022.


#include "OpenDoor.h"

#include "Kismet/GameplayStatics.h"


UOpenDoor::UOpenDoor()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw=InitialYaw;
	TargetOpenedDoorYaw = InitialYaw + OpenedAngle;
	
	ActorThatOpen = GetWorld()->GetFirstPlayerController()->GetPawn();

	if(!PreassurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("No preassure plate has been assigned"))
	}
	
	if(!ActorThatOpen)
	{
		UE_LOG(LogTemp, Error, TEXT("Pawn actor couldn't be found"))
	}
}

void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(IsValid(ActorThatOpen) && IsValid(PreassurePlate) && PreassurePlate->IsOverlappingActor(ActorThatOpen))
	{
		OpenDoor(DeltaTime);
		DoorLastOpened = GetWorld()->GetTimeSeconds();
	}
	else
	{
		if(GetWorld()->GetTimeSeconds() - DoorLastOpened > TimeToCloseDoor)
		{
			CloseDoor(DeltaTime);
		}
	}
}

void UOpenDoor::OpenDoor(float DeltaTime)
{
	CurrentYaw = FMath::FInterpConstantTo(CurrentYaw, TargetOpenedDoorYaw, DeltaTime, DegreesPerSecondWhenOpening);
	
	FRotator DoorRotation = GetOwner()->GetActorRotation();

	DoorRotation.Yaw = CurrentYaw;

	GetOwner()->SetActorRotation(DoorRotation);
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
	CurrentYaw = FMath::FInterpConstantTo(CurrentYaw, InitialYaw, DeltaTime, DegreesPerSecondWhenClosing);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
}

