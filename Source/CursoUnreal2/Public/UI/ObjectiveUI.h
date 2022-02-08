// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ObjectiveUI.generated.h"

UCLASS()
class CURSOUNREAL2_API UObjectiveUI : public UUserWidget
{
	GENERATED_BODY()
	FString ObjectiveDesc;
public:
	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* Canvas;

	UFUNCTION(BlueprintCallable, Category=Quests)
	void SetObjective(FString Objective);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Quests)
	FString GetObjective();

	void CompleteObjective();
};
