// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto Tank = GetAITank();
	if (Tank != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Tank is %s"), *(Tank->GetName()))
	}

	auto TankPlayer = GetWorld()->GetFirstPlayerController()->GetPawn();	
	
	if (TankPlayer == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not Found PlayerController!!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found PlayerController!!, Name is %s"), *TankPlayer->GetName());
	}
	
}


ATank* ATankAIController::GetAITank() const
{
	

	return Cast<ATank>(GetPawn());
}
