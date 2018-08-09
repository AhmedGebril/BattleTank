// Fill out your copyright notice in the Description page of Project Settings.

#include "AiTankController.h"
#include "Tank.h"
#include "public/Tank.h"



 void AAiTankController::Tick(float DeltaTime) {

	Super::Tick(DeltaTime);

	// Aim At the Player Tank position
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

	//Fire at The Player With A reloading time
	

	//Move To The Player
	MoveToActor(GetPlayerTank(), AcceptanceRadius);
	
}

ATank* AAiTankController:: GetControlledTank() {

	return Cast<ATank>(GetPawn());
}

void AAiTankController::BeginPlay()
{
	Super::BeginPlay();
	
}

ATank* AAiTankController:: GetPlayerTank()
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank) {
		return nullptr;
	}
	return Cast<ATank>(PlayerTank);
}



 