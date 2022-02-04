// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "QuestInterface.generated.h"

UINTERFACE(Blueprintable, BlueprintType)
class UQuestInterface : public UInterface
{
	GENERATED_BODY()
};

class CURSOUNREAL2_API IQuestInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Quest)
	virtual void OnPickup(){}
	UFUNCTION(BlueprintCallable, Category = Quest)
	virtual void OnItemUse(){}
	UFUNCTION(BlueprintCallable, Category = Quest)
	virtual void OnPointReached(){}
	UFUNCTION(BlueprintCallable, Category = Quest)
	virtual void OnActorActivated(){}
};
