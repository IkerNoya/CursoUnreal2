// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "DoorComponentBase.h"
#include "Components/ActorComponent.h"
#include "Interactable.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CURSOUNREAL2_API UInteractable : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Door)
	AActor* Actor;
public:	
	// Sets default values for this component's properties
	UInteractable();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	UFUNCTION(BlueprintCallable, Category=Interact)
	void ActivateActor();

		
};
