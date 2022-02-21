// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Interface/ElectricityInterface.h"
#include "Components/TextRenderComponent.h"
#include "CursoUnreal2/EscapeRoom/SwitchBase.h"
#include "ElectricSwitch.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API AElectricSwitch : public ASwitchBase, public IElectricityInterface
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UTextRenderComponent* HintText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings", meta = (ClampMin = 1.0))
	int32 ElectricityNeededToActivate = 1;
	
	int32 ElectricityCount=0;

public:
	AElectricSwitch();
	
	virtual void AddElectricity() override;
	virtual void RemoveElectricity() override;

protected:
	 virtual void BeginPlay() override;
};
