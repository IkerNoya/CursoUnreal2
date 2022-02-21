// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "Interface/InteractionInterface.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

UCLASS()
class CURSOUNREAL2_API AItemBase : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPickUp, AItemBase*, PickedItem);
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Items);
	TSubclassOf<class UItem> Item;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Mesh)
	UStaticMeshComponent* Mesh=nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Components)
	UBoxComponent* Box;

	
public:	
	// Sets default values for this actor's properties
	AItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	
	virtual void HandleInteraction() override;
};
