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

void ATankPlayerController::AimAtTheCrossHair() {

	FVector HitLocation; //OutParameter.

	if (GetSightRayHitLocation(HitLocation)) {

		
		GetControlledTank()->AimAt(HitLocation);

	}
	//tell controlled tank to aim at this
}
//GET THE world location of linetrace through crosshair, return true if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) {

	//find the crosshair location in pixel coordinates.
	int32 ViewportSizeX;
	int32 ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(CrossHairXlocation * ViewportSizeX, CrossHairYlocation * ViewportSizeY);
	//de_project the screen position coordinates
	FVector WorldDirection;
	FVector CamraLocation;
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CamraLocation, WorldDirection);
	// trace the ray and see if it hits something 
	FHitResult Hits;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (WorldDirection * Reach);
	GetWorld()->LineTraceSingleByChannel(Hits, StartLocation, EndLocation, ECC_Visibility);
	if (Hits.bBlockingHit) {
		HitLocation = Hits.Location;
		return true;
	}
	return false;
}