// Copyright Iker Noya 2022.


#include "Quest/Quest.h"


// Sets default values
AQuest::AQuest()
{
	PrimaryActorTick.bCanEverTick = false;

}

void AQuest::CheckQuestCompletion()
{
	for(int i = 0; i < QuestData.Objectives.Num(); i++)
	{
		if(!QuestData.Objectives[i].bIsObjectiveComplete)
		{
			UE_LOG(LogTemp, Warning, TEXT("Not all objectives were completed"));
			return;
		}
	}
	CompleteQuest();
}

void AQuest::BeginPlay()
{
	Super::BeginPlay();
}

void AQuest::CompleteStepInObjective(int32 ObjectiveId)
{
	QuestData.Objectives[ObjectiveId].CurrentStep++;
	if(QuestData.Objectives[ObjectiveId].CurrentStep >= QuestData.Objectives[ObjectiveId].StepsToComplete)
	{
		QuestData.Objectives[ObjectiveId].bIsObjectiveComplete=true;
		CheckQuestCompletion();
		CheckQuestStatus.Broadcast(QuestData.Name);
	}
}

void AQuest::CompleteQuest()
{
	QuestData.bIsCompleted=true;
}


