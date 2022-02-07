// Copyright Iker Noya 2022.


#include "UI/ObjectiveUI.h"

#include "Blueprint/WidgetTree.h"
#include "Components/TextBlock.h"


void UObjectiveUI::NativeConstruct()
{
	Super::NativeConstruct();
	ObjectiveDescription = Cast<UTextBlock>(GetWidgetFromName(TEXT("ObjectiveDescription")));
	if(!ObjectiveDescription)
	{
		UE_LOG(LogTemp, Warning, TEXT("NO PA"));
	}
	
}
void UObjectiveUI::SetObjectiveText(FString Objective)
{
	ObjectiveDesc = Objective;
}

void UObjectiveUI::InitializeObjective()
{
	if(ObjectiveDescription)
	{
		ObjectiveDescription->SetText(FText::FromString(ObjectiveDesc));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NO PA x2"));
	}
}

void UObjectiveUI::CompleteObjective()
{
	//Tachar objetivo
}
