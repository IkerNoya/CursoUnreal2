// Copyright Iker Noya 2022.


#include "Quest/Tasks/DistanceWalkedTask.h"


#include "CursoUnreal2/MainPlayer.h"
#include "Quest/UserQuestComponent.h"

void UDistanceWalkedTask::SetDelegates()
{
	Super::SetDelegates();
	if (Player)
	{
		Player->PlayerMoving.AddDynamic(this, &UDistanceWalkedTask::AddDistance);
	}
}

void UDistanceWalkedTask::InitializeVariables()
{
	Super::InitializeVariables();

	if (Player)
	{
		Location = Player->GetActorLocation();
	}
}

void UDistanceWalkedTask::AddDistance()
{
	if(Player && QuestComponent)
	{
		DistanceTravelled += (Location - Player->GetActorLocation()).Size() * GetWorld()->GetDeltaSeconds();
		Location = Player->GetActorLocation();
		CheckList.DistanceTraveled = DistanceTravelled;
		SendData.Broadcast(CheckList);
	}
}
