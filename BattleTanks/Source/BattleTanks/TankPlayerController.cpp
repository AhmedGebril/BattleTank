// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
#include "public/Tank.h"
#include "Engine/World.h"
#include "Tank.h"
#include "Camera/PlayerCameraManager.h"
#include "TankPlayerController.h"



ATank*ATankPlayerController::GetControlledTank()const {

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankPlayerController::Tick(float DeltaTime) {

	Super::Tick(DeltaTime);
	AimAtTheCrossHair();

}

void ATankPlayerController::AimAtTheCrossHair( ) {

	FVector HitLocation; //OutParameter.
    //tell controlled tank to aim at this
	if (GetHitLocation(HitLocation)){

		GetControlledTank()->AimAt(HitLocation);
	}
}
	


//GET THE world location of linetrace through crosshair, return true if it hits the landscape
bool ATankPlayerController::GetHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);

	FVector LookDirection;
	FVector StartLocation;
	// de-project the cords to the screen logout
	bool bDeprojected = DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		StartLocation,
		LookDirection
	);
	//Get the Hit Location.
	if (bDeprojected)
	{
		FHitResult HitResult;
		FVector EndLocation = StartLocation + LookDirection * LineTraceRange;
		bool bLineTraceHit = GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility);
			
			if (bLineTraceHit)
			{
				HitLocation = HitResult.Location;
				return true;
			}

	}
	return false;
}