// Copyright Iker Noya 2022.


#include "Puzzles/ElectricSwitch.h"


AElectricSwitch::AElectricSwitch()
{
	HintText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Hint Text"));
	HintText->SetupAttachment(RootComponent);
}

void AElectricSwitch::AddElectricity()
{
	IElectricityInterface::AddElectricity();
	ElectricityCount++;
	if(ElectricityCount>=ElectricityNeededToActivate)
	{
		bIsButtonActivated=true;
	}
	HintText->SetText(FText::FromString(FString::Printf(TEXT("%d / %d"), ElectricityCount, ElectricityNeededToActivate)));
}

void AElectricSwitch::RemoveElectricity()
{
	IElectricityInterface::RemoveElectricity();
	ElectricityCount--;
	if(ElectricityCount < ElectricityNeededToActivate)
	{
		bIsButtonActivated=false;
	}
	HintText->SetText(FText::FromString(FString::Printf(TEXT("%d / %d"), ElectricityCount, ElectricityNeededToActivate)));

}

void AElectricSwitch::BeginPlay()
{
	Super::BeginPlay();
	HintText->SetText(FText::FromString(FString::Printf(TEXT("%d / %d"), ElectricityCount, ElectricityNeededToActivate)));

}
