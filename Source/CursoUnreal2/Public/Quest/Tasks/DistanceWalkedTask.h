// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Quest/Tasks/TaskBase.h"
#include "DistanceWalkedTask.generated.h"

UCLASS()
class CURSOUNREAL2_API UDistanceWalkedTask : public UTaskBase
{
	GENERATED_BODY()
	FVector Location;
protected:
	UPROPERTY(VisibleAnywhere)
	float DistanceTravelled = 0;
	
	virtual void SetDelegates() override;
	virtual void InitializeVariables() override;
	UFUNCTION()
	void AddDistance();
};
