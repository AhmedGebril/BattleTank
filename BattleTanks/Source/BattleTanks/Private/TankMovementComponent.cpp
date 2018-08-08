// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"

void UTankMovementComponent::SetTracksReference(UTankTracks * RightTrackToSet, UTankTracks * LeftTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

}
void UTankMovementComponent::IntendToMoveForward(float Throw) {

	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

}

void  UTankMovementComponent::IntendToMoveRight(float Throw) {

	RightTrack->SetThrottle(-Throw);
	LeftTrack->SetThrottle(Throw);


}

