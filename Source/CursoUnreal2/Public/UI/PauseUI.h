// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "QuestUI.h"
#include "Blueprint/UserWidget.h"
#include "PauseUI.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API UPauseUI : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* Canvas;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UVerticalBox* ActiveQuest;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UVerticalBox* CompletedQuest;

protected:
	virtual void NativeConstruct() override;
};
