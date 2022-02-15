// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Data/QuestStruct.h"
#include "Engine/DataAsset.h"
#include "QuestDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API UQuestDataAsset : public UDataAsset
{
	GENERATED_BODY()


public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	TMap<int32, FQuestData> Quests;
};
