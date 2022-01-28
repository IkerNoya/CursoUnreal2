// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CURSOUNREAL2_API UInteractComponent : public UActorComponent
{
	GENERATED_BODY()

	FVector PlayerLocation;
	FRotator PlayerRotation;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Settings)
	float InteractDistance = 50.f;

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
