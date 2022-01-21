// Copyright Iker Noya 2022.


#include "Switch.h"

#include "DoorBase.h"
#include "Interactable.h"

// Sets default values
ASwitch::ASwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent=Box;
	
	SwitchBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	SwitchBase->SetupAttachment(Box);
	
	Button = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Button"));
	//NO OLVIDAR; ESTO VA EN CONSTRUCTOR
	Button->SetupAttachment(Box);
	
	InteractableComponent = CreateDefaultSubobject<UInteractable>(TEXT("Interactable Component"));
}

// Called when the game starts or when spawned
void ASwitch::BeginPlay()
{
	Super::BeginPlay();
}

void ASwitch::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	InteractableComponent->OnInteract.AddDynamic(this, &ASwitch::ActivateDoor);
}

// Called every frame
void ASwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ASwitch::ActivateDoor()
{
	if(ActorToActivate)
	{
		ADoorBase* Door = Cast<ADoorBase>(ActorToActivate);
		if(Door)
		{
			Door->TryInteractWithDoor();
		}
	}
}


