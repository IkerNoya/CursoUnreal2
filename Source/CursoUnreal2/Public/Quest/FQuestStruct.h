// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Quest/QuestCheckList.h"
#include "FQuestStruct.generated.h"

#define ID_QUEST_SIZE 5
#define ID_OBJECTIVE_SIZE 3

UENUM()
enum class EObjectiveType
{
	None,
	Collect,
	Interaction,
	Combat,
	Traversal
};

USTRUCT(BlueprintType)
struct CURSOUNREAL2_API FObjectivesStruct
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	EObjectiveType Type;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	FString Description;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Objective)
	int32 Id;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	FQuestCheckList CheckList;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	bool bIsObjectiveComplete;
	

	FObjectivesStruct()
	{
		Type = EObjectiveType::None;

		Description = "This is an Objective";
		Id = 0;
		
		bIsObjectiveComplete = false;
	}
	void CheckObjectiveComplete(FQuestCheckList List)
	{
		if(List.KillCounter == CheckList.KillCounter && List.DistanceTraveled >= CheckList.DistanceTraveled
			&& List.InteractedObject == CheckList.InteractedObject)
		{
			bIsObjectiveComplete=true;
		}
	}
};
