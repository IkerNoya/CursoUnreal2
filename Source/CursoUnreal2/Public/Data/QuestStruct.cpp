#include "QuestStruct.h"

bool FQuestData::CheckInitialized()
{
	return Name != NAME_None && Objectives.Num()>0;
}

FName FQuestData::GetQuestName()
{
	return Name;
}

void FQuestData::CheckQuestStatus(FQuestCheckList CheckList)
{
	bool bShouldQuestBeCompleted = true;
	for (FObjectiveStruct& Objective : Objectives)
	{
		Objective.CheckData(CheckList);
		if (!Objective.bIsComplete)
		{
			bShouldQuestBeCompleted = false;
		}
	}
	
	if (bShouldQuestBeCompleted)
	{
		CompleteQuest();
	}
}

void FQuestData::CompleteQuest()
{
	SetQuestState(Completed);
}

EQuestState FQuestData::GetState()
{
	return State;
}

void FQuestData::SetQuestState(EQuestState NewState)
{
	State = NewState;
}
