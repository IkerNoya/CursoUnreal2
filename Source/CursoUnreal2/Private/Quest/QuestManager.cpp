// Copyright Iker Noya 2022.


#include "Quest/QuestManager.h"

#include "Kismet/GameplayStatics.h"


AQuestManager::AQuestManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AQuestManager::ActivateQuest(AQuest* Quest)
{
	if(ActiveQuests.Num() < MaxActiveQuest && Quest->GetQuestState() == EQuestState::Inactive)
	{
		Quest->SetQuestState(EQuestState::Active);
		ActiveQuests.Add(Quest);
	}
	UE_LOG(LogTemp, Warning, TEXT("Reached Maximum number of active quests"));
}

void AQuestManager::BeginPlay()
{

	Super::BeginPlay();
	AHUD* AuxHud = GetWorld()->GetFirstPlayerController()->GetHUD();
	Hud = Cast<AMainHUD>(AuxHud);
	if(!Hud)
	{
		UE_LOG(LogTemp, Error, TEXT("Hud not found in %s"), *GetName());
	}
	TArray<int32> Keys;
	Quests.GenerateKeyArray(Keys);
	for(int i = 0; i < Quests.Num(); i++)
	{
		if(Quests.Contains(Keys[i]))
		{
			ActivateQuest(Quests[Keys[i]]);
			Quests[Keys[i]]->OnCompleteQuest.AddDynamic(this, &AQuestManager::OnQuestCompleted);
		}
	}
	
}

AQuest* AQuestManager::GetQuestByName(FName Name)
{
	for(int i = 0; i < Quests.Num(); i++)
	{
		if(Quests.Contains(i) && Quests[i] && Quests[i]->QuestData.Name == Name)
		{
			return Quests[i];
		}
	}
	return nullptr;
}

AQuest* AQuestManager::GetQuestById(int32 QuestId)
{
	if(Quests.Contains(QuestId))
	{
		return Quests[QuestId];
	}
	return nullptr;
	
}

void AQuestManager::OnQuestCompleted()
{
	//Cositas extras
}

void AQuestManager::AddQuest(AQuest* NewQuest)
{
	if(NewQuest)
	{
		TArray<int32> Ids;
		Quests.GenerateKeyArray(Ids);
		int32 Id = FMath::Max(Ids) + 1;
		ActivateQuest(NewQuest);
		NewQuest->OnCompleteQuest.AddDynamic(this, &AQuestManager::OnQuestCompleted);
		Quests.Add(Id, NewQuest);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Quest is Invalid"));
	}
}

void AQuestManager::RemoveQuest(int32 Id)
{
	if(Quests.Contains(Id))
	{
		Quests.Remove(Id);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Quest is Invalid"));
	}
}

