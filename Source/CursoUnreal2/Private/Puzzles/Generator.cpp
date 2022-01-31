// Copyright Iker Noya 2022.


#include "Puzzles/Generator.h"


// Sets default values
AGenerator::AGenerator()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = SceneRoot;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(SceneRoot);

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	Box->SetupAttachment(SceneRoot);

	CableConnectionSocket = CreateDefaultSubobject<USceneComponent>(TEXT("Cable Connection"));
	CableConnectionSocket->SetupAttachment(SceneRoot);
}

void AGenerator::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	Box->OnComponentBeginOverlap.AddDynamic(this, &AGenerator::OnOverlapBegin);
	Box->OnComponentEndOverlap.AddDynamic(this, &AGenerator::OnOverlapEnd);
}

// Called when the game starts or when spawned
void AGenerator::BeginPlay()
{
	Super::BeginPlay();
}

void AGenerator::AddElectricity()
{
	for (int i = 0; i < ActorsToActivate.Num(); i++)
	{
		if (ActorsToActivate[i])
		{
			ActorsToActivate[i]->AddElectricity();
		}
	}
}

void AGenerator::RemoveElectricity()
{
	for (int i = 0; i < ActorsToActivate.Num(); i++)
	{
		if (ActorsToActivate[i])
		{
			ActorsToActivate[i]->RemoveElectricity();
		}
	}
}

void AGenerator::OnOverlapBegin(UPrimitiveComponent* Component, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                                int32 OtherIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetClass() == Cable)
	{
		AddElectricity();
		AttachCable(OtherComp);
	}

}

void AGenerator::OnOverlapEnd(UPrimitiveComponent* Component, AActor* OtherActor,
                              UPrimitiveComponent* OtherComp, int32 OtherIndex)
{
	if (OtherActor->GetClass() == Cable)
	{
		RemoveElectricity();
		DetachCable();
	}
}
