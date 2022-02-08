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
	if(QuestManager)
	{
		QuestManager->OnQuestActivated.AddDynamic(this, &UUserQuestComponent::AddActiveQuest);
		ActiveQuest = QuestManager->GetQuests();
	}
	
}

void UUserQuestComponent::AddActiveQuest(AQuest* NewQuest)
{
	ActiveQuest.Add(NewQuest);
}

