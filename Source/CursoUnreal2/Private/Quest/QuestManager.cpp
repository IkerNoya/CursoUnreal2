// Copyright Iker Noya 2022.


#include "Quest/QuestManager.h"

#include "Kismet/GameplayStatics.h"


AQuestManager::AQuestManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AQuestManager::ActivateQuest(AQuest* Quest)
{
	if(Hud)
	{
		Hud->AddQuestWidget(Quest);
	}
	if (ActiveQuests.Num() < MaxActiveQuest && Quest->GetQuestState() == EQuestState::Inactive)
	{
		Quest->SetQuestState(EQuestState::Active);
		ActiveQuests.Add(Quest);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Reached Maximum number of active quests"));
	}
	
}

void AQuestManager::ActivateQuest(FQuestData& Quest)
{
	if(ActiveQuestData.Num() < MaxActiveQuest && Quest.GetState() == EQuestState::Inactive)
	{
		Quest.SetQuestState(Active);
		ActiveQuestData.Add(Quest);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Reached Maximum number of active quests in second array"));
	}
}

void AQuestManager::BeginPlay()
{
	Super::BeginPlay();
	AHUD* AuxHud = GetWorld()->GetFirstPlayerController()->GetHUD();
	Hud = Cast<AMainHUD>(AuxHud);
	if (!Hud)
	{
		UE_LOG(LogTemp, Error, TEXT("Hud not found in %s"), *GetName());
	}
	TArray<int32> Keys;
	Quests.GenerateKeyArray(Keys);
	for (int32 Id : Keys)
	{
		if (Quests.Contains(Id))
		{
			ActivateQuest(Quests[Id]);
			Quests[Keys[Id]]->OnCompleteQuest.AddDynamic(this, &AQuestManager::OnQuestCompleted);
		}
	}
	if(Data)
	{
		RowNames = Data->GetRowNames();
		FString Context = "Get Quest";
		for(FName RowName : RowNames)
		{
			UE_LOG(LogTemp, Warning, TEXT("NAMES: %s"), *RowName.ToString());
			FQuestData* Row = Data->FindRow<FQuestData>(RowName, Context);
			if(Row)
			{
				AddQuest(*Row);
			}
		}
		
	}

}

AQuest* AQuestManager::GetQuestByName(FName Name)
{
	TArray<int32> Ids;
	Quests.GenerateKeyArray(Ids);
	Ids.Sort();
	for (int32 Id : Ids)
	{
		if (Quests.Contains(Id) && Quests[Id] && Quests[Id]->GetQuestName() == Name)
		{
			return Quests[Id];
		}
	}
	return nullptr;
}

AQuest* AQuestManager::GetQuestById(int32 QuestId)
{
	if (Quests.Contains(QuestId))
	{
		return Quests[QuestId];
	}
	return nullptr;
}

void AQuestManager::OnQuestCompleted(AQuest* Quest)
{
	if (Quest)
	{
		Quest->SetQuestState(EQuestState::Completed);
	}
}

void AQuestManager::AddQuest(AQuest* NewQuest)
{
	if (NewQuest)
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

void AQuestManager::AddQuest(FQuestData NewQuest)
{
	if(NewQuest.CheckInitialized())
	{
		TArray<int32> Ids;
		QuestStructMap.GenerateKeyArray(Ids);
		int32 NewId = FMath::Max(Ids) + 1;
		ActivateQuest(NewQuest);
		QuestStructMap.Add(NewId, NewQuest);
	}	
}

void AQuestManager::RemoveQuest(int32 Id)
{
	if (Quests.Contains(Id))
	{
		Quests.Remove(Id);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Quest is Invalid"));
	}
}

void AQuestManager::CheckQuestStatus(FQuestCheckList CheckList)
{
	for (auto Quest : ActiveQuests)
	{
		if (Quest && Quest->GetQuestState() == EQuestState::Active)
		{
			Quest->CheckQuestStatus(CheckList);
		}
	}
	TArray<int32> Ids;
	Quests.GenerateKeyArray(Ids);
	Ids.Sort();
	for (int32 Id : Ids)
	{
		if (Quests.Contains(Id))
		{
			if (ActiveQuests.Contains(Quests[Id]) && Quests[Id]->GetQuestState() == EQuestState::Completed)
			{
				ActiveQuests.Remove(Quests[Id]);
			}
		}

	}
}
