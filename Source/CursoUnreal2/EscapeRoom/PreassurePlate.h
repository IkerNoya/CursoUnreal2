// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "DoorBase.h"
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
	float MassToActivate = 50.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings)
	ADoorBase* DoorToActivate = nullptr;

public:
	APreassurePlate();

protected:
	virtual void PostInitializeComponents() override;

	virtual void BeginPlay() override;

	UFUNCTION()
	void OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION()
	void OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor);

private:
	bool IsCurrentMassEnoughToActivate();
};
