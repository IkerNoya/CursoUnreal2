// Copyright Iker Noya 2022.


#include "Quest/Objectives/KillObjective.h"

void UKillObjective::CheckData(FQuestCheckList CheckList)
{
	if(bIsCompleted)
	{
		return;
	}
	
	Super::CheckData(CheckList);
	CurrentKills = CheckList.KillCounter;
	if(CurrentKills >= KillsNeeded)
	{
		bIsCompleted=true;
	}
}
