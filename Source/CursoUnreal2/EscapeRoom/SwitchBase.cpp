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

	InteractableComp = CreateDefaultSubobject<UInteractable>(TEXT("Interactable Component"));
}

void ASwitchBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASwitchBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	InteractableComp->OnInteract.AddDynamic(this, &ASwitchBase::ActivateSwitch);
}

void ASwitchBase::ActivateSwitch()
{
	if(ButtonSound)
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), ButtonSound, GetActorLocation());
	}
	//funcionalidad a activar en hijos
}


