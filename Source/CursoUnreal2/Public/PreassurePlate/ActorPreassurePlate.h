// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "ElectricityInterface.h"
#include "PreassurePlate/PreassurePlateBase.h"
#include "ActorPreassurePlate.generated.h"

/**
 * 
 */
UCLASS()
class CURSOUNREAL2_API AActorPreassurePlate : public APreassurePlateBase, public IElectricityInterface
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	bool bIsActivated = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	TSubclassOf<AActor> ActorToCompleteActivation;
	
	virtual void HandleInteraction() override;
	virtual void OnOverlapBegin(UPrimitiveComponent* Component, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnOverlapEnd(UPrimitiveComponent* Component, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherIndex) override;
};
