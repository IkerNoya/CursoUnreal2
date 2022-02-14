// Copyright Iker Noya 2022.


#include "Quest/Objectives/TraversalObjective.h"

void UTraversalObjective::CheckData(FQuestCheckList CheckList)
{
	if(bIsCompleted)
	{
		return;
	}
	Super::CheckData(CheckList);
	DistanceTraveled = CheckList.DistanceTraveled;
	if(DistanceTraveled>=DistanceToTravel)
	{
		bIsCompleted = true;
	}
}
