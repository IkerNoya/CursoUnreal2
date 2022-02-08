// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Quest/FQuestStruct.h"
#include "QuestDataAsset.generated.h"

UCLASS()
class CURSOUNREAL2_API UQuestDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FQuestStruct> Quests;
};
