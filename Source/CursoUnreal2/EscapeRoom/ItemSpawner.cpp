// Copyright Iker Noya 2022.


#include "ItemSpawner.h"

#include "Kismet/KismetArrayLibrary.h"


// Sets default values
AItemSpawner::AItemSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItemSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItemSpawner::SpawnItem()
{
	int32 ChosenIndex = FMath::RandRange(0, Items.Num()-1);
	GetWorld()->SpawnActor<AActor>(Items[ChosenIndex], GetActorLocation(), FRotator::ZeroRotator);
}

