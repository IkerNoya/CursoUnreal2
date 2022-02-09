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
	
}
