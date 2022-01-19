// Copyright Iker Noya 2022.


#include "OpenDoor.h"

#include "Actor.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"

#define OUT

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

	FindAudioComponent();
	CheckIfPreassurePlateExists();

	
}

void UOpenDoor::FindAudioComponent()
{
	DoorSound = GetOwner()->FindComponentByClass<UAudioComponent>();
	if(!DoorSound)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't find audio component in Actor: %s"), *GetOwner()->GetName())
	}
	
}

void UOpenDoor::CheckIfPreassurePlateExists()
{
	if(!PreassurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("No preassure plate has been assigned"))
	}
}

void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(TotalMassOfActors()>MassToOpenDoor)
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

	if(DoorSound && !OpenDoorSound)
	{
		DoorSound->Play();
		OpenDoorSound=true;
		CloseDoorSound=false;
	}
}

void UOpenDoor::CloseDoor(float DeltaTime)
{
	CurrentYaw = FMath::FInterpConstantTo(CurrentYaw, InitialYaw, DeltaTime, DegreesPerSecondWhenClosing);
	FRotator DoorRotation = GetOwner()->GetActorRotation();
	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);
	
	if(DoorSound &&  !CloseDoorSound)
	{
		DoorSound->Play();
		CloseDoorSound=true;
		OpenDoorSound=false;
	}
}

float UOpenDoor::TotalMassOfActors() const
{
	float TotalMass = 0.f;
	TArray<AActor*> ActorsOverlapping;
	if(!PreassurePlate)
	{
		return TotalMass;
	}
	
	PreassurePlate->GetOverlappingActors(OUT ActorsOverlapping);
	for(AActor* Actor : ActorsOverlapping)
	{
		if(Actor)
		{
			UPrimitiveComponent* Component = Actor->FindComponentByClass<UPrimitiveComponent>();
			if(Component)
			{
				TotalMass+=Component->GetMass();
			}
		}
	}
	return TotalMass;
}

