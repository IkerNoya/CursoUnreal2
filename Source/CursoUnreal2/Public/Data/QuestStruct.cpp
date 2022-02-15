#include "QuestStruct.h"

FName FQuestData::GetQuestName()
{
	return Name;
}

void FQuestData::CheckQuestStatus(FQuestCheckList CheckList)
{
	bool bShouldQuestBeCompleted = true;
	for(UObjectiveBase* Objective : Objectives)
	{
		if(Objective)
		{
			Objective->CheckData(CheckList);
			if(!Objective->bIsCompleted)
			{
				bShouldQuestBeCompleted = false;
			}
		}
	}
	if(bShouldQuestBeCompleted)
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
