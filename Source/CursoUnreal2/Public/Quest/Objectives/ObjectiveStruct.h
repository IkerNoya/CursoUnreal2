// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Quest/QuestCheckList.h"
#include "ObjectiveStruct.generated.h"


USTRUCT(BlueprintType)
struct FObjectiveStruct : public FTableRowBase
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
	virtual ~FObjectiveStruct() = default;

	FObjectiveStruct()
	{
		Description = "";
		NeededProgress = 1;
		CurrentProgress = 0;
		CheckList = FQuestCheckList();
		bIsComplete = false;
	}

	virtual void CheckData(FQuestCheckList List)
	{
		if (List.KillCounter >= CheckList.KillCounter && List.InteractedObject == CheckList.InteractedObject &&
			List.DistanceTraveled >= CheckList.DistanceTraveled)
		{
			bIsComplete=true;
		}
	}
};
