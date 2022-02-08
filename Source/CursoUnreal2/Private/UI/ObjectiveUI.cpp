// Copyright Iker Noya 2022.


#include "UI/ObjectiveUI.h"

void UObjectiveUI::SetObjective(FString Objective)
{
	ObjectiveDesc = Objective;
}

FString UObjectiveUI::GetObjective()
{
	return ObjectiveDesc;
}

void UObjectiveUI::CompleteObjective()
{
	//Tachar objetivo
}
