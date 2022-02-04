// Copyright Iker Noya 2022.


#include "Quest/QuestManager.h"

#include "Android/AndroidRuntimeSettings/Classes/AndroidRuntimeSettings.h"

// Sets default values
AQuestManager::AQuestManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AQuestManager::BeginPlay()
{
	Super::BeginPlay();
	for (AQuest* Quest : Quests)
	{
		Quest->CheckQuestStatus.AddDynamic(this, &AQuestManager::CheckQuestStatus);
	}
}

AQuest* AQuestManager::GetQuestByName(FName Name)
{
	AQuest* ReturnedQuest = nullptr;
	for (AQuest* Quest : Quests)
	{
		if (Quest && Quest->QuestData.Name == Name)
		{
			ReturnedQuest = Quest;
			break;
		}
	}
	return ReturnedQuest;
}

void AQuestManager::CheckQuestStatus(FName QuestName)
{
	AQuest* Quest = GetQuestByName(QuestName);
	if (Quest && Quest->QuestData.bIsCompleted)
	{
		Quest->QuestData.bIsActive = false;
		// TODO: Manejo de UI - Condimentar a gusto
	}
}
