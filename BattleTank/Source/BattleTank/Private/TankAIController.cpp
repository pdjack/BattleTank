// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"




void ATankAIController::Tick(float DeltaTime)
{
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (!ControlledTank) return;

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerTank) return;


	ControlledTank->AimAt(PlayerTank->GetActorLocation());
	ControlledTank->Fire();
}


