// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "MainHUD.h"
#include "ObjectiveUI.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "Quest/Quest.h"
#include "QuestUI.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API UQuestUI : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* Canvas;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = UI)
	AMainHUD* Hud;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UVerticalBox* QuestBox;


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* QuestTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quests, meta = (ExposeOnSpawn = true))
	AQuest* Quest;

	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Quests)
	void CreateObjectives(AQuest* QuestObjective);
	
};
