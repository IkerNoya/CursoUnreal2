// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API AMainHUD : public AHUD
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = UI)
	void OpenPause();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = UI)
	void ActivateWinWidget();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Quests)
	void AddQuestWidget(class AQuest* Quest);
};
