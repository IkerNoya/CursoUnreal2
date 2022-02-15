// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Quest/QuestCheckList.h"
#include "ObjectiveStruct.generated.h"


USTRUCT(BlueprintType)
struct FObjectiveStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	int32 NeededProgress;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Objective)
	int32 CurrentProgress;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	FQuestCheckList CheckList;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Objective)
	bool bIsComplete;

private:
	int KillCount = 0;
	float DistanceTraveled = 0.f;

public:
	FObjectiveStruct()
	{
		Description = "";
		NeededProgress = 1;
		CurrentProgress = 0;
		CheckList = FQuestCheckList();
		bIsComplete = false;
	}

	void CheckData(FQuestCheckList List)
	{
		if (CheckList.KillCounter == List.KillCounter && CheckList.InteractedObject == List.InteractedObject &&
			CheckList.DistanceTraveled == List.DistanceTraveled)
		{
			bIsComplete=true;
		}
	}
};
