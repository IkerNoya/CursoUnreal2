// Copyright Iker Noya 2022.


#include "MainPlayer.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Items/Item.h"

// Sets default values
AMainPlayer::AMainPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Grabber = CreateDefaultSubobject<UGrabberComponent>(TEXT("Grabber"));
	InteractComponent = CreateDefaultSubobject<UInteractComponent>(TEXT("Interact"));
	Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
	Inventory->Capacity=20;
}

void AMainPlayer::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if(PlayerInputComponent)
	{
		PlayerInputComponent->BindAxis("Forward", this, &AMainPlayer::MoveForward);
		PlayerInputComponent->BindAxis("Right", this, &AMainPlayer::MoveRight);
		PlayerInputComponent->BindAxis("Turn", this, &AMainPlayer::Turn);
		PlayerInputComponent->BindAxis("LookUp", this, &AMainPlayer::LookUp);

		PlayerInputComponent->BindAction("Grab", IE_Pressed, this, &AMainPlayer::Grab);
		PlayerInputComponent->BindAction("Grab", IE_Released, this, &AMainPlayer::Drop);
		
		PlayerInputComponent->BindAction("Crouch", IE_Pressed, this, &AMainPlayer::HandleCrouch);	
		PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AMainPlayer::Interact);
		PlayerInputComponent->BindAction("ShowInventory", IE_Pressed, this, &AMainPlayer::HandleInventory);
	}
}

void AMainPlayer::MoveForward(float Value)
{
	if(Value)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AMainPlayer::MoveRight(float Value)
{
	if(Value)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AMainPlayer::Turn(float Value)
{
	if(Value)
	{
		AddControllerYawInput(Value);
	}
}

void AMainPlayer::LookUp(float Value)
{
	if(Value)
	{
		AddControllerPitchInput(Value);
	}
}

void AMainPlayer::HandleCrouch()
{
	if(bIsCrouched)
	{
		UnCrouch();
	}
	else
	{
		Crouch();
	}
}


void AMainPlayer::Grab()
{
	if(Grabber)
	{
		Grabber->Grab();
	}
}

void AMainPlayer::Drop()
{
	if(Grabber)
	{
		Grabber->Drop();
	}
}

void AMainPlayer::Interact()
{
	if(InteractComponent)
	{
		InteractComponent->Interact();
		if(Inventory->ItemEquipped)
		{
			Inventory->ItemEquipped=nullptr;
		}
	}	
}

void AMainPlayer::UseItem(UItem* Item)
{
	if(Item)
	{
		Item->Use(this);
		Item->OnUse(this);
	}
}

