// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "DoorComponentBase.h"
#include "Engine/TriggerBox.h"
#include "PreassurePlate.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API APreassurePlate : public ATriggerBox
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings)
	float MassToActivate=50.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings)
	AActor* ActorToActivate = nullptr;

	virtual void BeginPlay() override;
public:
	APreassurePlate();

	virtual void Tick(float DeltaSeconds) override;

private:
	float TotalMassOfActorsOverlapping();
	UPROPERTY()
	UDoorComponentBase* DoorComponent = nullptr;
};
