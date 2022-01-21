// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "ItemSpawner.h"
#include "SwitchBase.h"
#include "ItemSpawnerSwitch.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API AItemSpawnerSwitch : public ASwitchBase
{
	GENERATED_BODY()
protected:
	UPROPERTY()
	AItemSpawner* ItemSpawner;

	virtual void BeginPlay() override;
public:
	virtual void ActivateSwitch() override;
};
