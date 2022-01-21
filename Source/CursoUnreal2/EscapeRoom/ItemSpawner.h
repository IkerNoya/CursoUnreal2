// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemSpawner.generated.h"

UCLASS()
class CURSOUNREAL2_API AItemSpawner : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Items)
	TArray<TSubclassOf<AActor>> Items;
public:	
	
	AItemSpawner();

protected:

	virtual void BeginPlay() override;
	
public:

	void SpawnItem();

};
