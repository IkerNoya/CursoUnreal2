// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Interface/ElectricityInterface.h"
#include "GameFramework/Actor.h"
#include "Items/ItemBase.h"
#include "BasketBallPuzzle.generated.h"

UCLASS()
class CURSOUNREAL2_API ABasketBallPuzzle : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UBoxComponent* PointTrigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UParticleSystem* ScoreParticles;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	TSubclassOf<AActor> Ball;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	TArray<TScriptInterface<IElectricityInterface>> ActorsToAddElectricity;
public:	
	// Sets default values for this actor's properties
	ABasketBallPuzzle();

protected:
	virtual void PostInitializeComponents() override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* Component, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherIndex, bool bFromSweep, const FHitResult& Sweep);

	void AddElectricity();

};
