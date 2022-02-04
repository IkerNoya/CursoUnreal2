// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "FQuestStruct.generated.h"

USTRUCT(BlueprintType)
struct FObjectivesStruct
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	int32 StepsToComplete;

	int32 CurrentStep;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	bool bIsObjectiveComplete;

	FObjectivesStruct()
	{
		Description = "This is an Objective";
		StepsToComplete = 1;

		CurrentStep=0;
		bIsObjectiveComplete=false;
	}
};

USTRUCT(BlueprintType)
struct CURSOUNREAL2_API FQuestStruct
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	int32 Id;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	TArray<FObjectivesStruct> Objectives;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	bool bIsActive;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	bool bIsCompleted;

	FQuestStruct()
	{
		Name = "Quest";
		Id=0;

		bIsActive=false;
		bIsCompleted=false;
	}
};
