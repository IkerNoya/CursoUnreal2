// Copyright Iker Noya 2022.


#include "Quest/Tasks/TaskBase.h"
#include "Quest/UserQuestComponent.h"

void UTaskBase::InitializeVariables()
{
	if (QuestComponent)
	{
		AActor* PlayerToFind = QuestComponent->GetOwner();
		if (PlayerToFind)
		{
			AMainPlayer* FoundPlayer = Cast<AMainPlayer>(PlayerToFind);
			if (FoundPlayer)
			{
				Player = FoundPlayer;
			}
		}
	}
}

void UTaskBase::BeginDestroy()
{
	SendData.Clear();
	UObject::BeginDestroy();
}

void UTaskBase::InitializeTask(UUserQuestComponent* Component)
{
	QuestComponent = Component;
	InitializeVariables();
	SetDelegates();
}
