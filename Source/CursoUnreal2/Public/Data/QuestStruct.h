#pragma once
#include "Engine/DataTable.h"
#include "Quest/Objectives/ObjectiveStruct.h"

#include "QuestStruct.generated.h"

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
	GENERATED_USTRUCT_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	TArray<FObjectiveStruct> Objectives;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Quest)
	TEnumAsByte<EQuestState> State;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Quest)
	FDataTableRowHandle RowHandle;

	FQuestData()
	{
		Name = "";

		State = Inactive;
	}
	
	FName GetQuestName();
	
	void CheckQuestStatus(FQuestCheckList CheckList);

	void CompleteQuest();

	EQuestState GetState();
	void SetQuestState(EQuestState NewState);
	
};
