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

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AiForwardIntention = MoveVelocity.GetSafeNormal();
	// To Get The Angle Between TankForward And AiForwardIntention
	auto ForwardThrow = FVector::DotProduct(TankForward, AiForwardIntention);

	IntendToMoveForward(ForwardThrow);

}

