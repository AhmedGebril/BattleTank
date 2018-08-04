// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::TurretRotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -6, +6);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto NewElevation = RelativeRotation.Yaw + ElevationChange;
	
	SetRelativeRotation(FRotator(0, NewElevation, 0));

}
