// Copyright Iker Noya 2022.


#include "Quest/Objectives/KillObjectiveStruct.h"

void FKillObjectiveStruct::CheckData(FQuestCheckList List)
{
	if(bIsComplete) return;
	
	CurrentProgress = List.KillCounter;
	if(CurrentProgress >= NeededProgress)
	{
		bIsComplete=true;
	}
}
