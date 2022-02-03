// Copyright Iker Noya 2022.


#include "PreassurePlate/ActorPreassurePlate.h"

#include "Components/BillboardComponent.h"
#include "Items/Item.h"

void AActorPreassurePlate::BeginPlay()
{
	Super::BeginPlay();
	
}

void AActorPreassurePlate::HandleInteraction()
{
	Super::HandleInteraction();
	for(int i = 0; i < ActorsToActivate.Num(); i++)
	{
		if(ActorsToActivate[i])
		{
			ActorsToActivate[i]->ActivateActor();
		}
	}
}

void AActorPreassurePlate::OnOverlapBegin(UPrimitiveComponent* Component, AActor* OtherActor,
                                          UPrimitiveComponent* OtherComp, int32 OtherIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor->GetClass() == ActorToCompleteActivation)
	{
		HandleInteraction();
	}
}

void AActorPreassurePlate::OnOverlapEnd(UPrimitiveComponent* Component, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherIndex)
{
	
}
