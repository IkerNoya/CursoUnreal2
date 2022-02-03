// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "ElectricityInterface.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Generator.generated.h"

UCLASS()
class CURSOUNREAL2_API AGenerator : public AActor
{
	GENERATED_BODY()

	bool bHasAlreadyGivenElectricity=false;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
	UBoxComponent* Box;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* CableConnectionSocket;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	TArray<TScriptInterface<IElectricityInterface>> ActorsToActivate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Settings")
	TSubclassOf<AActor> Cable;

	AGenerator();

protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;

public:
	void AddElectricity();
	void RemoveElectricity();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* Component, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                    int32 OtherIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* Component, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	                  int32 OtherIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void AttachCable(UPrimitiveComponent* OtherComp);
	UFUNCTION(BlueprintImplementableEvent)
	void DetachCable();
};
