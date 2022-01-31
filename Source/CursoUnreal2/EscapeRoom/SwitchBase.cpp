// Copyright Iker Noya 2022.


#include "SwitchBase.h"

#include "Kismet/GameplayStatics.h"

ASwitchBase::ASwitchBase()
{
	PrimaryActorTick.bCanEverTick = false;
	Box=CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Switch Base"));
	Base->SetupAttachment(Box);
	Button = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button"));
	Button->SetupAttachment(Box);

}

void ASwitchBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASwitchBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ASwitchBase::HandleInteraction()
{
	IInteractionInterface::HandleInteraction();
	if(ButtonSound)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), ButtonSound, GetActorLocation());
	}
	for(int i = 0; i < ActorsToActivate.Num(); i++)
	{
		if(ActorsToActivate[i])
		{
			ActorsToActivate[i]->ActivateActor();
		}
	}
}


