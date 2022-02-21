// Copyright Iker Noya 2022.


#include "Items/ItemBase.h"

#include "Player/MainPlayer.h"
#include "Items/Item.h"

// Sets default values
AItemBase::AItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;
	Mesh=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Box);

}

void AItemBase::BeginPlay()
{
	Super::BeginPlay();
}

void AItemBase::HandleInteraction()
{
	IInteractionInterface::HandleInteraction();
	APawn* Pawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	AMainPlayer* Player = Cast<AMainPlayer>(Pawn);
	if(Player)
	{
		if(Item)
		{
			bool CouldAddItem = Player->Inventory->AddItem(NewObject<UItem>(Player->Inventory, Item));
			if(!CouldAddItem)
			{
				GEngine->AddOnScreenDebugMessage(-1,1,FColor::Red, TEXT("Inventory is Full"));
				return;
			}
			Destroy();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Couldn't get Item"));
		}
		
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Couldn't get player character"));
	}
}


