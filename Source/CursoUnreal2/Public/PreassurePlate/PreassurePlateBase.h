// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Interface/ActivationInterface.h"
#include "Interface/InteractionInterface.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "PreassurePlateBase.generated.h"

UCLASS(Abstract)
class CURSOUNREAL2_API APreassurePlateBase : public AActor, public IInteractionInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Settings)
	TArray<TScriptInterface<IActivationInterface>> ActorsToActivate;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = Components)
	UBoxComponent* TriggerBox = nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = Components)
	UStaticMeshComponent* Plate = nullptr;

	bool bWasActive = false;

public:
	// Sets default values for this actor's properties
	APreassurePlateBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:

	virtual void HandleInteraction() override;
	
	UFUNCTION()
	virtual void OnOverlapBegin(UPrimitiveComponent* Component, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void OnOverlapEnd(UPrimitiveComponent* Component, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherIndex);
};
