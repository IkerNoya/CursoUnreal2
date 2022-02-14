// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "Components/ActorComponent.h"
#include "InteractComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSendInteractedObject, TSubclassOf<AActor>, InteractedObject);
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CURSOUNREAL2_API UInteractComponent : public UActorComponent
{
	GENERATED_BODY()

	FVector PlayerLocation;
	FRotator PlayerRotation;

public:
	UPROPERTY(BlueprintAssignable)
	FSendInteractedObject SendInteractedObject;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	float InteractDistance = 50.f;

	
	virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
public:
	UInteractComponent();
	
private:
	void FindPlayerLocationAndRotation();
	FVector CalculateLineTraceEnd();
	
public:	
	// Sets default values for this component's properties
	
	void UseItem(class UItem* Item);
	void Interact();
};
