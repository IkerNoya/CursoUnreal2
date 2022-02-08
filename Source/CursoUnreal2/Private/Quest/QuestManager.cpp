// Copyright Iker Noya 2022.


#include "Quest/QuestManager.h"

#include "Kismet/GameplayStatics.h"


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
	AHUD* AuxHud = GetWorld()->GetFirstPlayerController()->GetHUD();
	Hud = Cast<AMainHUD>(AuxHud);
	if(!Hud)
	{
		UE_LOG(LogTemp, Error, TEXT("Hud not found in %s"), *GetName());
	}
	
	for (AQuest* Quest : Quests)
	{
		Quest->CheckQuestStatus.AddDynamic(this, &AQuestManager::CheckQuestStatus);
		Quest->QuestData.bIsActive=true;
		if(Hud)
		{
			Hud->AddQuestWidget(Quest);
		}
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
	}
}

void AQuestManager::AddQuest(AQuest* NewQuest)
{
	if(NewQuest)
	{
		NewQuest->QuestData.bIsActive = true;
		Quests.Add(NewQuest);
		OnQuestActivated.Broadcast(NewQuest);
		if(Hud)
		{
			Hud->AddQuestWidget(NewQuest);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Quest is Invalid"));
	}
}

void AQuestManager::RemoveQuest(AQuest* Quest)
{
	if(Quest)
	{
		Quests.Remove(Quest);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Quest is Invalid"));
	}
}

TArray<AQuest*>& AQuestManager::GetQuests()
{
	return Quests;
}

