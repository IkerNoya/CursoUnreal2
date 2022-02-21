// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Interface/ActivationInterface.h"
#include "GameFramework/Actor.h"
#include "ItemSpawner.generated.h"

UCLASS()
class CURSOUNREAL2_API AItemSpawner : public AActor, public IActivationInterface
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
	virtual void ActivateActor() override;

};
