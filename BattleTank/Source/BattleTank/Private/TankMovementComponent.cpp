// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"


void UTankMovementComponent::Initialise(UTankTrack * LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

	UE_LOG(LogTemp, Warning, TEXT("UTankMovementComponent::Initialize()"));
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
	if (!LeftTrack || !LeftTrack) { return; }
	//auto Name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s IntendMoveForward %f"), *Name, Throw)

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnLeft(float Throw)
{
	if (!LeftTrack || !LeftTrack) { return; }

	RightTrack->SetThrottle(Throw);
	LeftTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}