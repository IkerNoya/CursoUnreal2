// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Switch.generated.h"

class UInteractable;
UCLASS()
class CURSOUNREAL2_API ASwitch : public AActor
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, Category = Components)
	UInteractable* InteractableComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=Collision)
	UBoxComponent* Box;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=Components)
	UStaticMeshComponent* SwitchBase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Components)
	UStaticMeshComponent* Button;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Door)
	AActor* ActorToActivate;
	
public:	
	// Sets default values for this actor's properties
	ASwitch();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = Animation)
	void AnimateSwitch();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void ActivateActor();

};
