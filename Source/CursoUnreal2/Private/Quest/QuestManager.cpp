// Copyright Iker Noya 2022.


#include "Quest/QuestManager.h"

#include "Kismet/GameplayStatics.h"

AQuestManager::AQuestManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AQuestManager::ActivateQuest(int32 QuestId)
{
	if(CurrentActiveQuests < MaxActiveQuest && QuestStructMap[QuestId].GetState() == EQuestState::Inactive)
	{
		QuestStructMap[QuestId].SetQuestState(Active);
		if(Hud)
		{
			Hud->AddQuestWidget(QuestStructMap[QuestId]);
		}
		ActiveQuestKeys.Add(QuestId);
		CurrentActiveQuests++;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Reached Maximum number of active quests in active quest array"));
	}
}

FQuestData& AQuestManager::GetQuestFromId(int32 Id)
{
	return QuestStructMap[Id];
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

void AQuestManager::AddQuest(FQuestData NewQuest)
{
	if(NewQuest.CheckInitialized())
	{
		TArray<int32> Keys;
		QuestStructMap.GenerateKeyArray(Keys);
		int32 NewId = FMath::Max(Keys) + 1;
		QuestStructMap.Add(NewId, NewQuest);
		//NewQuest.Objectives.Add(CreateObject(Mapa[enum].Object));
		//newQuest.Objective[this].NeededProgress = x;
		//newQuest.Objectives[this].Object = x;
		if(QuestStructMap[NewId].bActivateOnStart)
		{
			ActivateQuest(NewId);
		}
	}	
}


void AQuestManager::CheckQuestStatus(FQuestCheckList CheckList)
{
	for (int32 Id : ActiveQuestKeys)
	{
		if (QuestStructMap[Id].CheckInitialized() && QuestStructMap[Id].GetState() == EQuestState::Active)
		{
			QuestStructMap[Id].CheckQuestStatus(CheckList);
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