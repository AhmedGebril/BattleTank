// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "TankAimingComponent.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "CoreMinimal.h"
#include "Projectile.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class AProjectile;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void TurretReference(UTankTurret* TurretToSet);

	UPROPERTY(EditAnywhere, category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;
	
	UFUNCTION(BlueprintCallable, Category = Fire)
		void Fire();

protected:

	UTankAimingComponent * AimingComponent;

	AProjectile* projectile;

	UTankBarrel* Barrel;


private:
	float LaunchSpeed = 1000000;
  

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
