// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAction.h"
#include "SActionEffect.generated.h"
class UParticleSystemComponent;
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API USActionEffect : public USAction
{
	GENERATED_BODY()
public:
	void StartAction_Implementation(AActor* Instigator) override;
	void StopAction_Implementation(AActor* Instigator) override;

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Effect")
	float Duration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Effect")
	float Period;


	FTimerHandle PeriodHandle;
	FTimerHandle DurationHandle;
	

	UFUNCTION(BlueprintNativeEvent, Category="Effect")
	void ExecutePeriodEffect(AActor* Instigator);


public:

	UFUNCTION(BlueprintCallable, Category = "Action")
	float GetTimeRemaining() const;


	USActionEffect();
};
