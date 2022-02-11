// Copyright Iker Noya 2022.


#include "Quest/UserQuestComponent.h"
#include "Core/MainGameMode.h"
#include "Kismet/GameplayStatics.h"


UUserQuestComponent::UUserQuestComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	
}



void UUserQuestComponent::BeginPlay()
{
	Super::BeginPlay();
	AMainGameMode* GameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if(GameMode)
	{
		QuestManager = GameMode->GetQuestManager();
	}
	for(UTaskBase* Task : Tasks)
	{
		if(Task)
		{
			Task->InitializeTask(this);
			Task->SendData.AddDynamic(this, &UUserQuestComponent::SendData);
		}
	}
	
}

void UUserQuestComponent::SendData(FQuestCheckList List)
{
	if(QuestManager)
	{
		QuestManager->CheckQuestStatus(List);
	}
}
