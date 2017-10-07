// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void UTankTurret::Azimuth(float RelativeSpeed)
{
	auto ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto AzimutheChange = ClampedRelativeSpeed * MaxDegreesPerSecond * (GetWorld()->DeltaTimeSeconds);
	auto RawNewRotation = RelativeRotation.Yaw + AzimutheChange;
	auto ClampedRotation = FMath::Clamp<float>(RawNewRotation, MinAzimuthDegrees, MaxAzimuthDegrees);
	SetRelativeRotation(FRotator(0, ClampedRotation, 0));
	
	UE_LOG(LogTemp, Warning, TEXT("UTankTurret::Azimuth(%f)!!"), RelativeSpeed);
}

