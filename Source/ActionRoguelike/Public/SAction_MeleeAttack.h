// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAction.h"
#include "SAction_MeleeAttack.generated.h"


class UAnimMontage;
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API USAction_MeleeAttack : public USAction
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, Category = "Attack")
	UAnimMontage* AttackAnim;

	UPROPERTY(EditAnywhere, Category = "Effects")
	UParticleSystem* AttackEffect;

	UPROPERTY(EditDefaultsOnly, Category = "Attack")
	float AttackAnimDelay;

	UPROPERTY(VisibleAnywhere, Category = "Effects")
	FName HandSocketName;

	UFUNCTION()
	void AttackDelay_Elapsed(ACharacter* InstigatorCharacter);

public:
	virtual void StartAction_Implementation(AActor* Instigator) override;

	USAction_MeleeAttack();
};
