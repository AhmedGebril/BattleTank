// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTracks.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTracks : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:

	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	

private:

	UPROPERTY(EditAnywhere, category = Setup)
	float TrackMaxDrivingForce = 4000000;
};
