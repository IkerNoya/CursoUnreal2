// Copyright Iker Noya 2022.


#include "UI/QuestUI.h"

#include "Kismet/GameplayStatics.h"
#include "Quest/ObjectivePickup.h"

void UQuestUI::NativeConstruct()
{
	Super::NativeConstruct();
	AHUD* AuxHud = GetWorld()->GetFirstPlayerController()->GetHUD();
	Hud = Cast<AMainHUD>(AuxHud);
	if (!Hud)
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't get HUD"));
	}
	if (Quest)
	{
		CreateObjectives(Quest);
		UE_LOG(LogTemp, Warning, TEXT("ENTRO En QUEST"));
	}
}
