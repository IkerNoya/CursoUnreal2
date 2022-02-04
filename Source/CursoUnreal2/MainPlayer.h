// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "GrabberComponent.h"
#include "Camera/CameraComponent.h"
#include "EscapeRoom/InteractComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Inventory/InventoryComponent.h"
#include "MainPlayer.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FActivatePause);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUpdateHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FGameOver);
UCLASS()
class CURSOUNREAL2_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()

	FRotator ObjectRotation = FRotator::ZeroRotator;
	FRotator OriginalTargetRotation = FRotator::ZeroRotator;

	bool bIsSprinting=false;
	
protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
	UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	USpringArmComponent* SpringArm;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
	UGrabberComponent* Grabber;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
	UInteractComponent* InteractComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float SprintSpeed = 500.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	float NormalSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	int32 Hp = 2;
	
	bool bIsRotatingObject = false;
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Gameplay)
	UInventoryComponent* Inventory;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Grabber)
	USceneComponent* TargetLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	bool bIsObjectInGrabbingDistance=false;
	
	// Sets default values for this character's properties
	AMainPlayer();

private:
	void CheckIfPlayerIsInGrabbingDistance();
	
protected:
	virtual void PostInitializeComponents() override;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = Gameplay)
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void HandleCrouch();
	void HandleSprint();
	
	void Grab();
	void Drop();
	void Throw();
	
	void Interact();
	UPROPERTY(BlueprintAssignable, Category = Gameplay)
	FActivatePause Pause;
	UPROPERTY(BlueprintAssignable, Category = Gameplay)
	FUpdateHealth DecreaseHp;
	UPROPERTY(BlueprintAssignable, Category = Gameplay)
	FUpdateHealth IncreaseHp;
	UPROPERTY(BlueprintAssignable, Category = Gameplay)
	FGameOver GameOver;
	void ActivatePause();
	
	UFUNCTION(BlueprintImplementableEvent, Category = Inventory)
	void HandleInventory();
	
	UFUNCTION(BlueprintCallable)
	void UseItem(class UItem* Item);

	virtual void BeginDestroy() override;

	void RotateObject();
	void StopRotatingObject();
};
