// Copyright Iker Noya 2022.


#include "Puzzles/BasketBallPuzzle.h"

#include <Actor.h>

#include "Kismet/GameplayStatics.h"

// Sets default values
ABasketBallPuzzle::ABasketBallPuzzle()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = SceneRoot;
	PointTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	PointTrigger->SetupAttachment(SceneRoot);
}

void ABasketBallPuzzle::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	PointTrigger->OnComponentBeginOverlap.AddDynamic(this, &ABasketBallPuzzle::OnOverlap);
}

// Called when the game starts or when spawned
void ABasketBallPuzzle::BeginPlay()
{
	Super::BeginPlay();
}

void ABasketBallPuzzle::OnOverlap(UPrimitiveComponent* Component, AActor* OtherActor, UPrimitiveComponent* OtherComp,
                                  int32 OtherIndex, bool bFromSweep, const FHitResult& Sweep)
{
	if (OtherActor->GetClass() == Ball)
	{
		UWorld* World = GetWorld();
		if (World && ScoreParticles)
		{
			UGameplayStatics::SpawnEmitterAtLocation(World, ScoreParticles, OtherActor->GetActorLocation());
		}
		OtherActor->Destroy();
		AddElectricity();
	}
}

void ABasketBallPuzzle::AddElectricity()
{
	for(TScriptInterface<IElectricityInterface> Actor : ActorsToAddElectricity)
	{
		if(Actor)
		{
			Actor->AddElectricity();
		}
	}
}
