// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed)
{
	auto ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto RotationChange = ClampedRelativeSpeed * MaxDegreesPerSecond * (GetWorld()->DeltaTimeSeconds);
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	//auto ClampedRotation = FMath::Clamp<float>(RawNewRotation, MinAzimuthDegrees, MaxAzimuthDegrees);
	SetRelativeRotation(FRotator(0, Rotation, 0));
	
	//UE_LOG(LogTemp, Warning, TEXT("UTankTurret::Azimuth(%f)!!"), RelativeSpeed);
}

