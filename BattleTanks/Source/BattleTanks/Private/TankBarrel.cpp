// Fill out your copyright notice in the Description page of Project Settings.
#include "TankBarrel.h"
#include "Engine/World.h"



void UTankBarrel::Elevate(float Elevate) {
	// we did the times to get the degreespersecond / and delta time to get in time per frames
	Elevate = FMath::Clamp<float>(Elevate, -1, +1);
	auto ElevationChange = Elevate * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewElevation = RelativeRotation.Pitch + ElevationChange;
	auto BarrelRotation = FMath::Clamp<float>(NewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(BarrelRotation, 0, 0));
}

