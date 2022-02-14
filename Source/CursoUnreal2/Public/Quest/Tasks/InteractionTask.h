// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "TaskBase.h"
#include "InteractionTask.generated.h"

UCLASS()
class CURSOUNREAL2_API UInteractionTask : public UTaskBase
{
	GENERATED_BODY()

	
protected:
	UPROPERTY(VisibleAnywhere, Category=Objetive)
	UInteractComponent* InteractComponent;
	
	virtual void SetDelegates() override;
	
	virtual void InitializeVariables() override;

	virtual void BeginDestroy() override;

	UFUNCTION()
	void GetInteractedObject(TSubclassOf<AActor> InteractedObject);
	
};
