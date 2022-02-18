// Copyright Iker Noya 2022.


#include "UI/MainHUD.h"

#include "Player/MainPlayerController.h"

void AMainHUD::AddQuestWidget(FQuestData& Quest)
{
	AMainPlayerController* PlayerController = Cast<AMainPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PlayerController)
	{
		UQuestUI* Widget = CreateWidget<UQuestUI>(PlayerController, QuestReference);
		if (Widget)
		{
			Widget->QuestData = Quest;
			QuestWidget.Add(Widget);
		}
	}
}
