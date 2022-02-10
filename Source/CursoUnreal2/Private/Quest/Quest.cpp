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