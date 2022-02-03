// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Components/TextRenderComponent.h"
#include "PreassurePlate/PreassurePlateBase.h"
#include "WeightPreassurePlate.generated.h"


UCLASS()
class CURSOUNREAL2_API AWeightPreassurePlate : public APreassurePlateBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=Components)
	UTextRenderComponent* WeightText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Settings)
	float MassToActivate=50.f;

	virtual void BeginPlay() override;
	
	virtual void HandleInteraction() override;

public:
	AWeightPreassurePlate();
private:
	bool IsMassEnoughToActivate();
	
};
