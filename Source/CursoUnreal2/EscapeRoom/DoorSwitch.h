// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "DoorBase.h"
#include "SwitchBase.h"
#include "DoorSwitch.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API ADoorSwitch : public ASwitchBase
{
	GENERATED_BODY()
	UPROPERTY()
	ADoorBase* DoorToActivate = nullptr;
protected:
	virtual void BeginPlay() override;
public:
	virtual void ActivateSwitch() override;
};
