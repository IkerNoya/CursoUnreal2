// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Components/BoxComponent.h"
#include "CursoUnreal2/Public/InteractionInterface.h"
#include "GameFramework/Actor.h"
#include "SwitchBase.generated.h"

UCLASS()
class CURSOUNREAL2_API ASwitchBase : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category=Collision)
	UBoxComponent* Box;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Mesh)
	UStaticMeshComponent* Base = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Mesh)
	UStaticMeshComponent* Button = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Activation)
	AActor* ActorToActivate = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Components)
	UInteractable* InteractableComp = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Audio)
	USoundBase* ButtonSound;
	
public:	
	// Sets default values for this actor's properties
	ASwitchBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:
	virtual void ActivateInteraction() override;
};
