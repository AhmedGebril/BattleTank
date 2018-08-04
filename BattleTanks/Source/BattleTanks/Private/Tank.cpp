// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"



// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::AimAt(FVector HitLocation)
{
     
	AimingComponent->AimAt(HitLocation,LaunchSpeed);

}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	AimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::TurretReference(UTankTurret * TurretToSet)
{
	AimingComponent->SetTurretlReference(TurretToSet);
}

void ATank::Fire()
{
	
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Fire")),
		Barrel->GetSocketRotation(FName("Fire"))
		);
	
	Projectile->LauchProjectile(LaunchSpeed);
}


// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

