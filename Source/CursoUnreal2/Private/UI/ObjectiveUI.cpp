// Copyright Iker Noya 2022.


#include "UI/ObjectiveUI.h"

void UObjectiveUI::SetObjective(FString Objective)
{
	ObjectiveDesc = Objective;
}

void UObjectiveUI::UpdateDescription(FObjectiveStruct &Objective)
{
	FString Desc = FString::Printf(TEXT("%s [%d/%d]"), *Objective.Description, 0,1);
	if(Description)
	{
		Description->SetText(FText::FromString(Desc));
	}
	else
	{
		UE_LOG(LogTemp, Warning,TEXT("No description Text"));
	}
}

FString UObjectiveUI::GetObjective()
{
	return ObjectiveDesc;
}

void UObjectiveUI::CompleteObjective()
{
	//Tachar objetivo
}
