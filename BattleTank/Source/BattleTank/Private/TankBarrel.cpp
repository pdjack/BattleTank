// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Engine/World.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevateChange = ClampedRelativeSpeed * MaxDegreesPerSecond * (GetWorld()->DeltaTimeSeconds);
	auto RawNewRotation =  RelativeRotation.Pitch + ElevateChange;
	auto ClampedRotation = FMath::Clamp<float>(RawNewRotation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(ClampedRotation, 0, 0));
	//UE_LOG(LogTemp, Warning, TEXT("UTankBarrel::Elevate called!!"));
}
