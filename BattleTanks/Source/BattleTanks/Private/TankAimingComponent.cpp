// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAimingComponent.h"
#include "Tank.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::AimAt(FVector HitLocation,float LaunchSpeed)
{
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Fire"));
	auto OurTank = GetOwner()->GetName();
	auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	

	bool BHaveAimSoultion = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
		);

	if (BHaveAimSoultion)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
	}	 
}
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto AimRotator = AimDirection.Rotation();
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto DeltaRotator = AimRotator - BarrelRotator;
	Barrel->Elevate( DeltaRotator.Pitch);
	if (DeltaRotator.Yaw > 180) {

		DeltaRotator.Yaw = -180;
	}
	Turret->TurretRotate(DeltaRotator.Yaw);
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
	
}

void UTankAimingComponent::SetTurretlReference(UTankTurret * TurretToSet)
{
	Turret = TurretToSet;
}


