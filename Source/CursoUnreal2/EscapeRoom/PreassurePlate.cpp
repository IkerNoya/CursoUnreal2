// Copyright Iker Noya 2022.


#include "PreassurePlate.h"

APreassurePlate::APreassurePlate()
{
}


void APreassurePlate::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	OnActorBeginOverlap.AddDynamic(this, &APreassurePlate::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &APreassurePlate::OnOverlapEnd);
}

void APreassurePlate::BeginPlay()
{
	Super::BeginPlay();
	DoorComponent = ActorToActivate->FindComponentByClass<UDoorComponentBase>();
	if(!DoorComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't Find component in actor: %s"), *ActorToActivate->GetName());
	}
}

void APreassurePlate::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("HOLA"))
	if(TotalMassOfActorsOverlapping()>=MassToActivate)
	{
		DoorComponent->ActivateDoor(true);
	}
	else
	{
		DoorComponent->ActivateDoor(false);
	}
}

void APreassurePlate::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	UE_LOG(LogTemp, Warning, TEXT("HOLA"))
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
	UE_LOG(LogTemp, Warning, TEXT("MASS: %f"), Mass);
	return Mass;
}
