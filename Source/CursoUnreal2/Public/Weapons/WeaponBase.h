// Copyright Iker Noya 2022.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

UCLASS()
class CURSOUNREAL2_API AWeaponBase : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Components)
	USceneComponent* ShootingPoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings)
	float MagazineAmmo = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Settings)
	float MaxAmmo = 1;
	
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	


};
