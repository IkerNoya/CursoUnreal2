// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Quest/Tasks/TaskBase.h"
#include "KillCounterTask.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API UKillCounterTask : public UTaskBase
{
	GENERATED_BODY()
protected:
	virtual void SetDelegates() override;
	virtual void InitializeVariables() override;
	
	UFUNCTION()
	void AddKill();
};
