// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Generator.generated.h"

UCLASS()
class CURSOUNREAL2_API AGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	AGenerator();

protected:
	virtual void BeginPlay() override;

public:	


};
