// Fill out your copyright notice in the Description page of Project Settings.
#include"Tank.h"
#include "AiTankController.h"


ATank*AAiTankController::GetControlledTank()const {

	return Cast<ATank>(GetPawn());
}

void AAiTankController::BeginPlay()
{
	Super::BeginPlay();
}

