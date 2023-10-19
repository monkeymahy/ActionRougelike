// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "SProjectileBase.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "SBlackHoleProjectile.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASBlackHoleProjectile : public ASProjectileBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	URadialForceComponent* RadialForce;

public:
	ASBlackHoleProjectile();
};
