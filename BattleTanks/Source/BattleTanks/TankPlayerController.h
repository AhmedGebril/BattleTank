// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

		 
	
public:
	ATank* GetControlledTank()const;	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime)override;
	void AimAtTheCrossHair();
	bool GetHitLocation(FVector& HitLocation) const;
	float CrosshairXLocation = 0.5;
	float CrosshairYLocation = 0.333;
	float LineTraceRange = 1000000;
};
