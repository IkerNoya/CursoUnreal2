// Copyright Iker Noya 2022.


#include "Quest/Objectives/PickUpObjective.h"

void UPickUpObjective::CheckData(FQuestCheckList CheckList)
{
	if(bIsCompleted)
	{
		return;
	}
	Super::CheckData(CheckList);
	if(CheckList.InteractedObject)
	{
		if(PickedUpItem == CheckList.InteractedObject)
		{
			CurrentAmountOfItems++;
			if(CurrentAmountOfItems >= AmountNeeded)
			{
				bIsCompleted=true;
			}
		}
	}
}
