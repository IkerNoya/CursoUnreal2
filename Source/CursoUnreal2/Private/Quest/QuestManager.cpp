// Copyright Iker Noya 2022.


#include "Quest/QuestManager.h"

#include "Kismet/GameplayStatics.h"
//CheckList
//Switch - Ni a palo!

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

void AQuestManager::ActivateQuest(int32 QuestId)
{
	if(CurrentActiveQuests < MaxActiveQuest && QuestStructMap[QuestId].GetState() == EQuestState::Inactive)
	{
		QuestStructMap[QuestId].SetQuestState(Active);
		ActiveQuestKeys.Add(QuestId);
		CurrentActiveQuests++;
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
			FQuestData* Row = Data->FindRow<FQuestData>(RowName, Context);
			if(Row)
			{
				AddQuest(*Row);
			}
		}
		QuestStructMap.GenerateKeyArray(QuestIds);
		QuestIds.Sort();
	}
	

}

AQuest* AQuestManager::GetQuestByName(FName Name)
{
	for (int32 Id : QuestIds)
	{
		if (Quests.Contains(Id) && Quests[Id] && Quests[Id]->GetQuestName() == Name)
		{
			return Quests[Id];
		}
	}
	return nullptr;
}

int32 AQuestManager::GetQuestIdFromName(FName Name)
{
	for(int32 Key : QuestIds)
	{
		if(QuestStructMap[Key].Name == Name)
		{
			return Key;
		}
	}
	return -1;
}

FQuestData& AQuestManager::GetQuestDataByName(FName Name)
{
	TArray<int32> Keys;
	QuestStructMap.GenerateKeyArray(Keys);
	for (int32 Key : Keys)
	{
		if(QuestStructMap.Contains(Key) && QuestStructMap[Key].Name == Name)
		{
			return QuestStructMap[Key];
		}
	}
	FQuestData QuestData = FQuestData();
	return QuestData;
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
		UE_LOG(LogTemp, Warning, TEXT("Id: %d"), Id);
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
		TArray<int32> Keys;
		QuestStructMap.GenerateKeyArray(Keys);
		int32 NewId = FMath::Max(Keys) + 1;
		QuestStructMap.Add(NewId, NewQuest);
		if(QuestStructMap[NewId].bActivateOnStart)
		{
			ActivateQuest(NewId);
		}
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
	for (int32 Id : ActiveQuestKeys)
	{
		if (QuestStructMap[Id].CheckInitialized() && QuestStructMap[Id].GetState() == EQuestState::Active)
		{
			QuestStructMap[Id].CheckQuestStatus(CheckList);
		}
	}
	
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
	for(int32 Id : QuestIds)
	{
		if(ActiveQuestKeys.Contains(Id) && QuestStructMap[Id].GetState() == EQuestState::Completed)
		{
			int32 QuestToActivateKey = GetQuestIdFromName(QuestStructMap[Id].QuestToActivateName);
			if(QuestToActivateKey >= 0)
			{
				ActivateQuest(QuestToActivateKey);
			}
			ActiveQuestKeys.Remove(Id);
		}
	}
}