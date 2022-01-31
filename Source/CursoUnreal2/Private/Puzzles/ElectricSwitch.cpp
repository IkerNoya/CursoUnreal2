// Copyright Iker Noya 2022.


#include "Puzzles/ElectricSwitch.h"

void AElectricSwitch::AddElectricity()
{
	IElectricityInterface::AddElectricity();
	ElectricityCount++;
	if(ElectricityCount>=ElectricityNeededToActivate)
	{
		bIsButtonActivated=true;
	}
	UE_LOG(LogTemp, Warning, TEXT("CURRENT ELECTRICITY: %d"), ElectricityCount)
}

void AElectricSwitch::RemoveElectricity()
{
	IElectricityInterface::RemoveElectricity();
	ElectricityCount--;
	if(ElectricityCount < ElectricityNeededToActivate)
	{
		bIsButtonActivated=false;
	}
	UE_LOG(LogTemp, Warning, TEXT("CURRENT ELECTRICITY: %d"), ElectricityCount)
}
