// Fill out your copyright notice in the Description page of Project Settings.

#include "MySProjectileBase.h"
#include <Kismet/GameplayStatics.h>
#include "Particles/ParticleSystemComponent.h"



void AMySProjectileBase::Explode_Implementation()
{

	UGameplayStatics::SpawnEmitterAtLocation(this, ImpactVisualEffects, GetActorLocation(), GetActorRotation(), true);
	Destroy();
}

void AMySProjectileBase::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && OtherActor != Cast<AActor>(GetInstigator())) {
		Explode();
	}
}
