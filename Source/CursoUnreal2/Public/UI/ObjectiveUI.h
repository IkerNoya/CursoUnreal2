// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Quest/Objectives/ObjectiveStruct.h"
#include "ObjectiveUI.generated.h"

UCLASS()
class CURSOUNREAL2_API UObjectiveUI : public UUserWidget
{
	GENERATED_BODY()
	FString ObjectiveDesc;
public:
	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* Canvas;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* Description;

	UFUNCTION(BlueprintCallable, Category=Quests)
	void SetObjective(FString Objective);

	UFUNCTION(BlueprintCallable, Category=Quests)
	void UpdateDescription(FObjectiveStruct &Objective);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Quests)
	FString GetObjective();

	void CompleteObjective();
};
