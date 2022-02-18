// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "ObjectiveUI.h"
#include "Blueprint/UserWidget.h"
#include "Components/CanvasPanel.h"
#include "Components/TextBlock.h"
#include "Data/QuestStruct.h"
#include "Components/VerticalBox.h"
#include "QuestUI.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API UQuestUI : public UUserWidget
{
	GENERATED_BODY()
	
	bool bHasCreatedObjectives=false;
	int32 ObjectiveSize = 0;
	
protected:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* Canvas;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = UI)
	class AMainHUD* Hud;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UVerticalBox* QuestBox;


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* QuestTitle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quests, meta = (ExposeOnSpawn = true))
	FQuestData QuestData;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	TArray<UObjectiveUI*> Objectives;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Quest)
	TSubclassOf<UObjectiveUI> ObjectiveWidget;
	
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintCallable, Category = Quests)
	void CreateObjectives(FQuestData& QuestObjective);
	
};
