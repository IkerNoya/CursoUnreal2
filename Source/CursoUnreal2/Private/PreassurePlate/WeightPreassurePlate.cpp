// Copyright Iker Noya 2022.


#include "PreassurePlate/WeightPreassurePlate.h"



void AWeightPreassurePlate::BeginPlay()
{
	Super::BeginPlay();
	WeightText->SetText(FString::Printf(TEXT("Weight\n 0 / %d"), FMath::RoundToInt(MassToActivate)));
}

void AWeightPreassurePlate::HandleInteraction()
{
	if(!bWasActive && IsMassEnoughToActivate())
	{
		for(int i = 0; i < ActorsToActivate.Num(); i++)
		{
			if(ActorsToActivate[i])
			{
				ActorsToActivate[i]->ActivateActor();
				bWasActive=true;
			}
		}
	}
	else if(bWasActive && !IsMassEnoughToActivate())
	{
		for(int i = 0; i < ActorsToActivate.Num(); i++)
		{
			if(ActorsToActivate[i])
			{
				ActorsToActivate[i]->ActivateActor();
				bWasActive=false;
			}
		}
	}
}

AWeightPreassurePlate::AWeightPreassurePlate()
{
	WeightText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Weight Text"));
	WeightText->SetupAttachment(RootComponent);
}

bool AWeightPreassurePlate::IsMassEnoughToActivate()
{
	float Mass = 0.f;
	TArray<AActor*> ActorsOverlapping;
	TriggerBox->GetOverlappingActors(ActorsOverlapping);
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
	WeightText->SetText(FString::Printf(TEXT("Weight\n %d / %d"), FMath::RoundToInt(Mass), FMath::RoundToInt(MassToActivate)));
	return Mass>=MassToActivate;
}
