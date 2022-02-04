// Copyright Iker Noya 2022.


#include "Quest/ObjectivePickup.h"

#include "Core/MainGameMode.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UObjectivePickup::UObjectivePickup()
{

	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UObjectivePickup::BeginPlay()
{
	Super::BeginPlay();
	AMainGameMode* GameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if(GameMode)
	{
		QuestManager = Cast<AQuestManager>(GameMode->GetQuestManager());
		if(!QuestManager)
		{
			UE_LOG(LogTemp, Error, TEXT("Could`t get Quest Manager"));
		}
	}
}

void UObjectivePickup::OnPickup()
{
	IQuestInterface::OnPickup();
	if(!bItemAlreadyPickedUp)
	{
		if(QuestManager)
		{
			AQuest* Quest = QuestManager->GetQuestByName(QuestName);
			if(Quest)
			{
				Quest->CompleteStepInObjective(ObjectiveId);
			}
		}
		bItemAlreadyPickedUp=true;
	}
}




