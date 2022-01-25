// Copyright Iker Noya 2022.


#include "PreassurePlate/PreassurePlateBase.h"

APreassurePlateBase::APreassurePlateBase()
{
	PrimaryActorTick.bCanEverTick = true;
	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	RootComponent = TriggerBox;
	Plate=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Plate"));
	Plate->SetupAttachment(TriggerBox);

}

void APreassurePlateBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void APreassurePlateBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &APreassurePlateBase::OnOverlapBegin);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &APreassurePlateBase::OnOverlapEnd);
}

// Called every frame
void APreassurePlateBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APreassurePlateBase::HandleInteraction()
{
	IInteractionInterface::HandleInteraction();
}

void APreassurePlateBase::OnOverlapBegin(UPrimitiveComponent* Component, AActor* OtherActor,
                                         UPrimitiveComponent* OtherComp, int32 OtherIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	HandleInteraction();
}

void APreassurePlateBase::OnOverlapEnd(UPrimitiveComponent* Component, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherIndex)
{
	HandleInteraction();
}

