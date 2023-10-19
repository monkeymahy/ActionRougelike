// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAction.h"
#include "SAction_Sprint.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API USAction_Sprint : public USAction
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category="Action")
	float Bonus_Speed;
public:
	virtual void StartAction_Implementation(AActor* Instigator) override;
	virtual void StopAction_Implementation(AActor* Instigator) override;

	USAction_Sprint();
	
};
