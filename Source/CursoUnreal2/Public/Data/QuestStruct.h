#pragma once

#include "Engine/DataTable.h"
#include "Quest/Objectives/ObjectiveStruct.h"

#include "QuestStruct.generated.h"

class FStructBaseChain;
class UObjective;
UENUM(BlueprintType)
enum EQuestState
{
	Inactive,
	Active,
	Completed,
	Failed
};

USTRUCT(BlueprintType)
struct FQuestData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	FName Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	TArray<FObjectiveStruct> Objectives;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	TEnumAsByte<EQuestState> State;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	FName QuestToActivateName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	bool bActivateOnStart;

	FQuestData()
	{
		Name = NAME_None;

		State = Inactive;

		bActivateOnStart = false;
	}

	bool CheckInitialized();

	FName GetQuestName();

	void CheckQuestStatus(FQuestCheckList CheckList);

	void CompleteQuest();

	EQuestState GetState();
	void SetQuestState(EQuestState NewState);
};
