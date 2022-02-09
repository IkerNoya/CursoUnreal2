// Copyright Iker Noya 2022.


#include "Quest/Quest.h"


// Sets default values
AQuest::AQuest()
{
	PrimaryActorTick.bCanEverTick = false;
	SetQuestState(EQuestState::Inactive);
}

void AQuest::CheckQuestCompletion()
{
	for (int i = 0; i < QuestData.Objectives.Num(); i++)
	{
		if (QuestData.Objectives.Contains(i) && !QuestData.Objectives[i].bIsObjectiveComplete)
		{
			UE_LOG(LogTemp, Warning, TEXT("Not all objectives were completed"));
			return;
		}
	}
	CompleteQuest();
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

void AQuest::CompleteStepInObjective(int32 ObjectiveId)
{
	if (QuestData.Objectives.Contains(ObjectiveId))
	{
		QuestData.Objectives[ObjectiveId].CurrentStep++;
	}
}

void AQuest::CompleteQuest()
{
	SetQuestState(EQuestState::Completed);
	OnCompleteQuest.Broadcast();
}

void AQuest::BeginDestroy()
{
	OnCompleteQuest.Clear();
	Super::BeginDestroy();
}
