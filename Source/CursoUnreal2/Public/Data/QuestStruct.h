#pragma once
#include "Engine/DataTable.h"
#include "Quest/Objectives/ObjectiveBase.h"

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
	UPROPERTY(Instanced, EditAnywhere, BlueprintReadOnly, Category = Quest)
	TArray<UObjectiveBase*> Objectives;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Quest)
	TEnumAsByte<EQuestState> State;

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
