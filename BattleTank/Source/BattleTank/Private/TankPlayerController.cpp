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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimForwardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimForwardsCrosshair()
{
	if (!GetControlledTank()) return;

	// Get World location if linetrace through crosshair
	// If it hits the landscape
		// Tell controlled tank  to aim at this point
}
