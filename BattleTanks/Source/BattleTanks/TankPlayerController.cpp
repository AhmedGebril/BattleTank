// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
#include "public/Tank.h"
#include "TankPlayerController.h"


ATank*ATankPlayerController::GetControlledTank()const {

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
}
