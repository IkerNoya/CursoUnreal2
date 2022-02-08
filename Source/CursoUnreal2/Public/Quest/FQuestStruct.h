// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "FQuestStruct.generated.h"

#define ID_QUEST_SIZE 5
#define ID_OBJECTIVE_SIZE 3
USTRUCT(BlueprintType)

struct FObjectivesStruct
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Objective)
	FString Id;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	int32 StepsToComplete;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Objective)
	int32 CurrentStep;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Objective)
	bool bIsObjectiveComplete;

	FObjectivesStruct()
	{
		Id = 0;
		Description = "This is an Objective";
		StepsToComplete = 1;

		CurrentStep=0;
		bIsObjectiveComplete=false;
		AssingObjectiveID();
	}
	void AssingObjectiveID()
	{
		TArray<FString> Alphanumeric = {"a","b","c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "u", "w", "x", "y", "z"
			, "1", "2", "3", "4", "5", "6", "7", "8", "9"};
		FString id;
		for(int i = 0; i < ID_OBJECTIVE_SIZE; i++)
		{
			int32 Index = FMath::RandRange(0, Alphanumeric.Num()-1);
			id.Append(Alphanumeric[Index]);
		}
		Id = id;
	}
};

USTRUCT(BlueprintType)
struct CURSOUNREAL2_API FQuestStruct
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	FName Name;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Quest)
	FString Id;
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
		AssignID();
	}

	void AssignID()
	{
		TArray<FString> Alphanumeric = {"a","b","c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "u", "w", "x", "y", "z"
			, "1", "2", "3", "4", "5", "6", "7", "8", "9"};
		FString id;
		for(int i = 0; i < ID_QUEST_SIZE; i++)
		{
			int32 Index = FMath::RandRange(0, Alphanumeric.Num()-1);
			id.Append(Alphanumeric[Index]);
			
		}
		Id = id;
	}
};
