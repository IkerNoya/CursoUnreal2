// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "GrabberComponent.h"
#include "EscapeRoom/InteractComponent.h"
#include "GameFramework/Character.h"
#include "Inventory/InventoryComponent.h"
#include "MainPlayer.generated.h"

UCLASS()
class CURSOUNREAL2_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()

	FRotator ObjectRotation = FRotator::ZeroRotator;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
	UGrabberComponent* Grabber;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
	UInteractComponent* InteractComponent;
	
	bool bIsRotatingObject = false;
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gameplay)
	UInventoryComponent* Inventory;
	
	// Sets default values for this character's properties
	AMainPlayer();
	
protected:
	virtual void PostInitializeComponents() override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void HandleCrouch();

	void Grab();
	void Drop();

	void Interact();

	UFUNCTION(BlueprintImplementableEvent, Category = Inventory)
	void HandleInventory();
	
	UFUNCTION(BlueprintCallable)
	void UseItem(class UItem* Item);

	void RotateObject();
	void StopRotatingObject();
};
