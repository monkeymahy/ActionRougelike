// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SProjectileBase.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "BlackHoleProjectile.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROUGELIKE_API ABlackHoleProjectile : public ASProjectileBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	URadialForceComponent* RadialForce;

public:
	ABlackHoleProjectile();


};
