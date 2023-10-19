// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SProjectileBase.h"
#include "MySProjectileBase.generated.h"
class UParticleSystem;
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API AMySProjectileBase : public AActor
{
	GENERATED_BODY()



	UPROPERTY(EditAnywhere, Category="Effects")
	UParticleSystem* ImpactVisualEffects;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Explode();

	UFUNCTION()
	virtual void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


	
};
