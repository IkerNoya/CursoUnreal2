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
	//Buscar como crear widget manualmente
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* ObjectiveDescription = nullptr;

	virtual void NativeConstruct() override;
	
	UFUNCTION(BlueprintCallable)
	void SetObjectiveText(FString Objective);

	void InitializeObjective();
	
	
	void CompleteObjective();
};
