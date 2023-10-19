// Fill out your copyright notice in the Description page of Project Settings.


#include "SBlackHoleProjectile.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "SAttributeComponent.h"


ASBlackHoleProjectile::ASBlackHoleProjectile()
{
	RadialForce = CreateDefaultSubobject<URadialForceComponent>("RadialForce");
	RadialForce->SetupAttachment(SphereComp);
	RadialForce->SetAutoActivate(true);
	RadialForce->Radius = 1000.0f;
	RadialForce->ImpulseStrength = -8000.0f;
	RadialForce->bImpulseVelChange = true;

	RadialForce->AddCollisionChannelToAffect(ECC_WorldDynamic);
	RadialForce->AddCollisionChannelToAffect(ECC_WorldStatic);
}