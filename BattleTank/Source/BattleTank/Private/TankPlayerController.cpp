// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	

	/*ATank* PossedTank = GetControlledTank();
	if (PossedTank == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("ControlledTank is missing!!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ControlledTank's name is %s"), *PossedTank->GetName());
	}*/
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


