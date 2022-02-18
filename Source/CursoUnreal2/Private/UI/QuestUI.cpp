// Copyright Iker Noya 2022.


#include "UI/QuestUI.h"
#include "UI/MainHUD.h"

#include "Kismet/GameplayStatics.h"
#include "Player/MainPlayerController.h"

void UQuestUI::NativeConstruct()
{
	Super::NativeConstruct();
	AHUD* AuxHud = GetWorld()->GetFirstPlayerController()->GetHUD();
	Hud = Cast<AMainHUD>(AuxHud);
	if (!Hud)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't get HUD"));
	}
	if (QuestData.CheckInitialized())
	{
		CreateObjectives(QuestData);
		UE_LOG(LogTemp, Warning, TEXT("ENTRO En QUEST"));
	}
}

void UQuestUI::CreateObjectives(FQuestData& QuestObjective)
{
	QuestData = QuestObjective;
	AMainPlayerController* PlayerController = Cast<AMainPlayerController>(GetWorld()->GetFirstPlayerController());
	if(QuestData.CheckInitialized() && PlayerController)
	{
		if(!bHasCreatedObjectives)
		{
			FString Name = FString::Printf(TEXT("%s"), *QuestData.Name.ToString());
			ObjectiveSize = QuestData.Objectives.Num(); // Cuestionable creacion de variable, borrar cuando todo funcione
			if(QuestTitle)
			{
				QuestTitle->SetText(FText::FromString(Name));
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("NO QUEST TITLE"));
			}
			for(FObjectiveStruct& Objective : QuestData.Objectives)
			{
				UObjectiveUI* Widget = CreateWidget<UObjectiveUI>(PlayerController, ObjectiveWidget);
				Objectives.Add(Widget);
				Widget->UpdateDescription(Objective);
				if(QuestBox)
				{
					QuestBox->AddChildToVerticalBox(Widget);
				}
				else
				{
					UE_LOG(LogTemp, Error, TEXT("No Vertical Box"));
				}
				bHasCreatedObjectives=true;
			}
		}
		else
		{
			for(int i = 0; i < Objectives.Num(); i++)
			{
				if(Objectives[i])
				{
					Objectives[i]->UpdateDescription(QuestData.Objectives[i]);
				}
			}
		}
	}
}
