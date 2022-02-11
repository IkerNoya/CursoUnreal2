// Copyright Iker Noya 2022.


#include "Quest/Tasks/KillCounterTask.h"

#include "CursoUnreal2/MainPlayer.h"
#include "Quest/UserQuestComponent.h"

void UKillCounterTask::SetDelegates()
{
	Super::SetDelegates();

	if (Player)
	{
		Player->Kill.AddDynamic(this, &UKillCounterTask::AddKill);
	}
}

void UKillCounterTask::InitializeVariables()
{
	Super::InitializeVariables();
}

void UKillCounterTask::AddKill()
{
	if (QuestComponent)
	{
		CheckList.KillCounter++;
		SendData.Broadcast(CheckList);
	}
}
