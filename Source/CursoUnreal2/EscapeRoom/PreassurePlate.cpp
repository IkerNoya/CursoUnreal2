// Copyright Iker Noya 2022.


#include "PreassurePlate.h"

void APreassurePlate::BeginPlay()
{
	Super::BeginPlay();
	DoorComponent = ActorToActivate->FindComponentByClass<UDoorComponentBase>();
	if(!DoorComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't Find component in actor: %s"), *ActorToActivate->GetName());
	}
}

APreassurePlate::APreassurePlate()
{
	
}


void APreassurePlate::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if(TotalMassOfActorsOverlapping()>=MassToActivate)
	{
		DoorComponent->ActivateDoor(true);
	}
	else
	{
		DoorComponent->ActivateDoor(false);
	}
}


float APreassurePlate::TotalMassOfActorsOverlapping()
{
	float Mass = 0.f;
	TArray<AActor*> ActorsOverlapping;
	GetOverlappingActors(ActorsOverlapping);
	for(AActor* Actor : ActorsOverlapping)
	{
		if(IsValid(Actor))
		{
			UPrimitiveComponent* OtherComponent = Actor->FindComponentByClass<UPrimitiveComponent>();
			if(IsValid(OtherComponent))
			{
				Mass+=OtherComponent->GetMass();
			}
		}
	}
	return Mass;
}
