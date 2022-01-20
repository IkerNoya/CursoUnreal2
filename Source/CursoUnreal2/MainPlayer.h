// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "GrabberComponent.h"
#include "EscapeRoom/InteractComponent.h"
#include "GameFramework/Character.h"
#include "MainPlayer.generated.h"

UCLASS()
class CURSOUNREAL2_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
	UGrabberComponent* Grabber;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Gameplay)
	UInteractComponent* InteractComponent;
public:
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

};
