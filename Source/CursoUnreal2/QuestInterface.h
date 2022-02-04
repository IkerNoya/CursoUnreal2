// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "QuestInterface.generated.h"

UINTERFACE(BlueprintType)
class UQuestInterface : public UInterface
{
	GENERATED_BODY()
};

class CURSOUNREAL2_API IQuestInterface
{
	GENERATED_BODY()

public:
	
	UFUNCTION(Category = Quest)
	virtual void OnPickup(){}
	UFUNCTION(Category = Quest)
	virtual void OnItemUse(){}
	UFUNCTION(Category = Quest)
	virtual void OnPointReached(){}
	UFUNCTION(Category = Quest)
	virtual void OnActorActivated(){}
};
