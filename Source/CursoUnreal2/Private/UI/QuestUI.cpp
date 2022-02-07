// Copyright Iker Noya 2022.


#include "UI/QuestUI.h"

#include "Kismet/GameplayStatics.h"
#include "Quest/ObjectivePickup.h"

void UQuestUI::NativeConstruct()
{
	Super::NativeConstruct();
	AHUD* AuxHud = GetWorld()->GetFirstPlayerController()->GetHUD();
	Hud = Cast<AMainHUD>(AuxHud);
	if(!Hud)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't get HUD"));
	}
	if(Quest)
	{
		QuestTitle->SetText(FText::FromString(Quest->QuestData.Name.ToString()));
		for(int i = 0; i < Quest->QuestData.Objectives.Num(); i++)
		{
			UObjectiveUI* Objective = CreateWidget<UObjectiveUI>(GetWorld()->GetFirstPlayerController(), UObjectiveUI::StaticClass());
			if(Objective)
			{
				Objective->SetObjectiveText(FString::Printf(TEXT("%s %d/%d"), *Quest->QuestData.Objectives[i].Description, Quest->QuestData.Objectives[i].CurrentStep, Quest->QuestData.Objectives[i].StepsToComplete));
				QuestBox->AddChildToVerticalBox(Objective);
				Objective->InitializeObjective();
			}
		}
	}

}
