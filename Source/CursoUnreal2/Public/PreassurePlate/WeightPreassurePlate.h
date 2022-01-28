// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "CursoUnreal2/EscapeRoom/DoorBase.h"
#include "CursoUnreal2/EscapeRoom/ItemSpawner.h"
#include "PreassurePlate/PreassurePlateBase.h"
#include "WeightPreassurePlate.generated.h"

UENUM()
enum class ETypeActor
{
	Door, Spawner
};

UCLASS()
class CURSOUNREAL2_API AWeightPreassurePlate : public APreassurePlateBase
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	float MassToActivate=50.f;
	UPROPERTY()
	ADoorBase* Door = nullptr;
	UPROPERTY()
	AItemSpawner* ItemSpawner = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Type)
	ETypeActor TypeActor;

	void HandleDoor();
	void HandleSpawner();

	virtual void BeginPlay() override;
	
	virtual void HandleInteraction() override;
	
private:
	bool IsMassEnoughToActivate();
	
};
