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

	FVector HitLocation(ForceInit);
	// Get world location of linetrace through crosshair
	if (GetSightRayHitLocation(OUT HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
		//UE_LOG(LogTemp,Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())
	}

	// If it hits the landscape
		// Tell controlled tank  to aim at this point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	UE_LOG(LogTemp, Warning, TEXT("ViewportSizeX: %d, ViewportSizeY:%d"), ViewportSizeX, ViewportSizeY)


	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, OUT LookDirection))
	{
		
		GetLookVectorHitLocation(IN LookDirection, OUT OutHitLocation);
		
		return true;
	}

	return false;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		OUT CameraWorldLocation, 
		OUT LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& LookDirection, FVector& OutHitLocation) const
{
	FVector LineStartLocation = PlayerCameraManager->GetCameraLocation();
	FVector LineEndLocation = LineStartLocation + (LookDirection * LineTraceRange);
	//FCollisionQueryParams FireTraceParams = FCollisionQueryParams(FName(TEXT("")), false, this);
	
	FHitResult HitResult;
	if (GetWorld()->LineTraceSingleByChannel(HitResult, LineStartLocation, LineEndLocation, ECC_Visibility))
	{
		OutHitLocation =  HitResult.Location;
		return true;
	}

	return false;
}
