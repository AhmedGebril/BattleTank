// Fill out your copyright notice in the Description page of Project Settings.
#include "TankTracks.h"
#include "Engine/World.h"





void UTankTracks::SetThrottle(float Throttle) {

    auto name = GetName();
	UE_LOG(LogTemp, Warning, TEXT(" %s Has A Value Of %f"),*name,Throttle);

	auto AppliedForce = GetForwardVector()* Throttle *TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(AppliedForce, ForceLocation);
	
}