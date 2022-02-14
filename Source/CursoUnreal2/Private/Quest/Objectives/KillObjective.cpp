// Copyright Iker Noya 2022.


#include "Quest/Objectives/KillObjective.h"

void UKillObjective::CheckData(FQuestCheckList CheckList)
{
	if (bIsCompleted)
	{
		return;
	}

	Super::CheckData(CheckList);
	if (CheckList.KillCounter >= CurrentProgress)
	{
		CurrentProgress = CheckList.KillCounter;
	}

	if (CurrentProgress >= ProgressNeededToComplete)
	{
		bIsCompleted = true;
	}
}
