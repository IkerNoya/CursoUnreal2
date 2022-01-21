// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interactable.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInteractableDelegate);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CURSOUNREAL2_API UInteractable : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractable();
	UPROPERTY(BlueprintAssignable, Category=Interact)
	FInteractableDelegate OnInteract;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

public:	
	// Called every frame
	UFUNCTION(BlueprintCallable, Category=Interact)
	void ActivateActor();

		
};
