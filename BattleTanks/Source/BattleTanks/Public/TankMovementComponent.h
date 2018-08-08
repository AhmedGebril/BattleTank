// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TankTracks.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankMovementComponent : public UNavMovementComponent
{

	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Setup)
	void IntendToMoveForward(float Throw);
	
	
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTracksReference(UTankTracks* RightTrackToSet,UTankTracks* LeftTrackToSet);


	UFUNCTION(BlueprintCallable, Category = Setup)
		void IntendToMoveRight(float Throw);



private:
	UTankTracks * RightTrack;
	UTankTracks * LeftTrack;
};
