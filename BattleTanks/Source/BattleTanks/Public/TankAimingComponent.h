// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "kismet/GamePlayStatics.h"
#include "CoreMinimal.h"
#include "TankTurret.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//forward declaretion.
class UTankBarrel;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void AimAt(FVector HitLocation,float LaunchSpeed);

	void SetBarrelReference(UTankBarrel* BarrelToSet);

	void SetTurretlReference(UTankTurret* TurretToSet);

	void MoveBarrelTowards(FVector AimDirection);

	void MoveTurretTowards(FVector AimDirection);
private:

	UTankBarrel * Barrel;

	UTankTurret * Turret;
};
