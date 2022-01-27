// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemBase.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class CURSOUNREAL2_API UItem : public UObject
{
	GENERATED_BODY()
public:
	UItem();

	UPROPERTY(Transient)
	UWorld* World;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=Items)
	FText InteractionText;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=Items)
	UStaticMesh* PickUpMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category=Items)
	UTexture2D* Thumbnail;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=Items)
	FText ItemDisplayName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=Items)
	FText ItemDescription;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category=Items, meta = (ClampMin = 0.0))
	float Weight;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Items)
	class UInventoryComponent* OwningInventory;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Items)
	TSubclassOf<AItemBase> ItemActor = nullptr;
	
	virtual void Use(class AMainPlayer* Player);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnUse(class AMainPlayer* Player);

	void SpawnActor(FVector Position);

	UWorld* GetItemWorld() const {return World;}
};
