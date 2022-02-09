// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FQuestStruct.generated.h"

#define ID_QUEST_SIZE 5
#define ID_OBJECTIVE_SIZE 3
USTRUCT(BlueprintType)

struct FObjectivesStruct : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	FString Description;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Objectives, meta = (ClampMin = 1.0))
	int32 StepsToComplete;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Objective)
	int32 CurrentStep;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	bool bIsObjectiveComplete;

	FObjectivesStruct()
	{
		Description = "This is an Objective";

		bIsObjectiveComplete=false;
	}
	
};

USTRUCT(BlueprintType)
struct CURSOUNREAL2_API FQuestStruct : public FTableRowBase
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	TMap<int32, FObjectivesStruct> Objectives;

	FQuestStruct()
	{
		Name = "Quest";
	}
};
