// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "QuestCheckList.generated.h"

USTRUCT(BlueprintType)
struct CURSOUNREAL2_API FQuestCheckList
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CheckList)
	int32 KillCounter;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CheckList)
	TScriptInterface<IInteractionInterface> InteractedObjects;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CheckList)
	float DistanceTraveled;

	FQuestCheckList()
	{
		KillCounter = 0;
		InteractedObjects = nullptr;
		DistanceTraveled = 0.f;
	}
	
};
