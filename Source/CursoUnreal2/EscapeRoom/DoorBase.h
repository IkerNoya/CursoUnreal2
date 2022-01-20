// Copyright Iker Noya 2022.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorBase.generated.h"

UCLASS()
//TODO: Tratar de crear cosas con la menor conexion entre si posibles
//Responsabilidad de puerta: Abrir y Cerrar
class CURSOUNREAL2_API ADoorBase : public AActor
{
	GENERATED_BODY()
protected:
	//Animacion de apertura/Cierre
	
	//USoundComponent
public:	
	ADoorBase();

protected:
	virtual void BeginPlay() override;
	
public:	
	virtual void Tick(float DeltaTime) override;
	//void TryOpenDoor
	//void CloseDoor
};
