// Copyright Iker Noya 2022.


#include "Quest/Objectives/TraversalObjective.h"

void UTraversalObjective::CheckData(FQuestCheckList CheckList)
{
	if (bIsCompleted)
	{
		return;
	}
	Super::CheckData(CheckList);
	if (CheckList.DistanceTraveled >= CurrentProgress)
	{
		CurrentProgress = CheckList.DistanceTraveled;
		if (CurrentProgress >= ProgressNeededToComplete)
		{
			bIsCompleted = true;
		}
	}
}
