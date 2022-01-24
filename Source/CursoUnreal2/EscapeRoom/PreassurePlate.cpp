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

}

void APreassurePlate::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if(DoorToActivate && IsCurrentMassEnoughToActivate())
	{
		DoorToActivate->TryInteractWithDoor();
	}
}

void APreassurePlate::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if(DoorToActivate && !IsCurrentMassEnoughToActivate())
	{
		DoorToActivate->TryInteractWithDoor();
	}
}

bool APreassurePlate::IsCurrentMassEnoughToActivate()
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
	return Mass>=MassToActivate;
}
