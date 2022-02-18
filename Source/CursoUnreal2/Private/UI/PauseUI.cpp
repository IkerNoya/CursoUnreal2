// Copyright Iker Noya 2022.


#include "UI/PauseUI.h"

#include "Core/MainGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Quest/QuestManager.h"
#include "UI/MainHUD.h"


void UPauseUI::NativeConstruct()
{
	Super::NativeConstruct();
	AMainGameMode* GameMode = Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		AQuestManager* QuestManager = GameMode->GetQuestManager();
		AMainHUD* HUD = Cast<AMainHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
		if (HUD && QuestManager && HUD->QuestWidget.Num() > 0 && ActiveQuest && CompletedQuest)
		{
			for (int i = 0; i < HUD->QuestWidget.Num(); i++)
			{
				if (HUD->QuestWidget[i])
				{
					HUD->QuestWidget[i]->QuestData = QuestManager->GetQuestDataByName(HUD->QuestWidget[i]->QuestData.Name);
					if (HUD->QuestWidget[i]->QuestData.GetState() == Completed)
					{
						CompletedQuest->AddChildToVerticalBox(HUD->QuestWidget[i]);
					}
					else
					{
						ActiveQuest->AddChildToVerticalBox(HUD->QuestWidget[i]);
					}
				}
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("No HUD/ActiveQuestBox/CompleteQuestBox"));
		}
	}
}
