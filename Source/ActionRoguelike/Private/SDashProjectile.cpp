// Fill out your copyright notice in the Description page of Project Settings.


#include "SDashProjectile.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "SAttributeComponent.h"
#include "Kismet/GameplayStatics.h"

ASDashProjectile::ASDashProjectile() {
	TeleportDelay = 0.2f;
	DetonateDelay = 0.2f;

	MovementComp->InitialSpeed = 6000.0f;

}

void ASDashProjectile::BeginPlay() {
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle_DelayDetonate, this, &ASDashProjectile::Explode, DetonateDelay);
}

void ASDashProjectile::Explode_Implementation() {

	GetWorldTimerManager().ClearTimer(TimerHandle_DelayDetonate);

	UGameplayStatics::SpawnEmitterAtLocation(this, ImpactVFX, GetActorLocation(), GetActorRotation());

	EffectComp->DeactivateSystem();

	MovementComp->StopMovementImmediately();
	SetActorEnableCollision(false);

	FTimerHandle TimerHandle_DelayTeleport;
	GetWorldTimerManager().SetTimer(TimerHandle_DelayTeleport, this, &ASDashProjectile::TeleportInstigator, TeleportDelay);



}

void ASDashProjectile::TeleportInstigator() {
	AActor* ActorTeleport = GetInstigator();
	if (ensureAlways(ActorTeleport)) {
		ActorTeleport->TeleportTo(GetActorLocation(), ActorTeleport->GetActorRotation(), false, false);
	}

	Destroy();
}

