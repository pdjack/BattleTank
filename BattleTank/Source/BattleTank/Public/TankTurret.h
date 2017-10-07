// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Azimuth(float RelativeSpeed);
	
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 5.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxAzimuthDegrees = 170.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinAzimuthDegrees = -170.f;
	
};
