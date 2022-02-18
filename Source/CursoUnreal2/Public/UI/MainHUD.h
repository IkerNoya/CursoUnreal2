// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "QuestUI.h"
#include "GameFramework/HUD.h"
#include "Data/QuestStruct.h"
#include "MainHUD.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API AMainHUD : public AHUD
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	TArray<UQuestUI*> QuestWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	TSubclassOf<UQuestUI> QuestReference;
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = UI)
	void OpenPause();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = UI)
	void ActivateWinWidget();
	UFUNCTION(BlueprintCallable, Category = Quests)
	void AddQuestWidget(FQuestData& Quest);
};
