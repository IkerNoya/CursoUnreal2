// Copyright Iker Noya 2022.


#include "Quest/Quest.h"

// Sets default values
AQuest::AQuest()
{
	PrimaryActorTick.bCanEverTick = false;
	SetQuestState(EQuestState::Inactive);
}


EQuestState AQuest::GetQuestState()
{
	return QuestState;
}

void AQuest::SetQuestState(EQuestState State)
{
	QuestState = State;
}

void AQuest::BeginPlay()
{
	Super::BeginPlay();
}

FName AQuest::GetQuestName()
{
	return Name;
}

void AQuest::CheckQuestStatus(FQuestCheckList CheckList)
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


void AQuest::CompleteQuest()
{
	SetQuestState(EQuestState::Completed);
	OnCompleteQuest.Broadcast(this);
}

void AQuest::BeginDestroy()
{
	OnCompleteQuest.Clear();
	Super::BeginDestroy();
}