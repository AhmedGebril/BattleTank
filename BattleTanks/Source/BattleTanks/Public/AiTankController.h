// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "AiTankController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANKS_API AAiTankController : public AAIController
{
	GENERATED_BODY()


		
public:
	ATank * GetControlledTank();
	virtual void Tick(float DeltaTime)override;
	virtual void BeginPlay() override;
	ATank * GetPlayerTank();

};