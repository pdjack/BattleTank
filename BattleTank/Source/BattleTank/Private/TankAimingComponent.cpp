// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Runtime/Engine/Classes/Engine/World.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	Turret = TurretToSet;
}

//// Called every frame
//void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

void UTankAimingComponent::AimAt(FVector WorldSpaceTarget, float LaunchSpeed)
{
	if (!Barrel) { return; }
	if (!Turret) { return; }

	auto StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	
	FVector OutLaunchVelocity;
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OUT OutLaunchVelocity,
		StartLocation,
		WorldSpaceTarget,
		LaunchSpeed,
		false,
		0.f,
		0.f,
		ESuggestProjVelocityTraceOption::DoNotTrace // don't remove this line for avoiding bug
	);

	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		
		MoveTurret(AimDirection);

		MoveBarrel(AimDirection);
		

		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f , AimSolution found"), Time)
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f , AimSolution Not found"), Time)
	}
}


void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	if (!Barrel) { return; }

	auto TankName = GetOwner()->GetName();
	auto AimAsRotator = AimDirection.Rotation();
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	//UE_LOG(LogTemp, Warning, TEXT("DeltaRotator   : %s from %s"), *DeltaRotator.ToString(), *TankName);

	Barrel->Elevate(DeltaRotator.Pitch); // it will be clamped to -1 ~ 1 in Evelvate()
}

void UTankAimingComponent::MoveTurret(FVector AimDirection)
{
	if (!Turret) { 
		UE_LOG(LogTemp, Warning, TEXT("Turret == nullptr"));
		return; 
	}
	auto TankName = GetOwner()->GetName();
	auto AimAsRotator = AimDirection.Rotation();
	auto BarrelRotator = Turret->GetForwardVector().Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("DeltaRotator   : %s from %s"), *DeltaRotator.ToString(), *TankName);

	Turret->Rotate(DeltaRotator.Yaw);// it will be clamped to -1 ~ 1 in Azimuth()
}
