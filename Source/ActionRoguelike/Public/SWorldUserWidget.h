// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <Components/SizeBox.h>
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SWorldUserWidget.generated.h"


class USzieBox;
/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API USWorldUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category="UI")
	FVector WordlOffset;

	UPROPERTY(BlueprintReadWrite, Category="UI", meta = (ExposeOnSpawn=true))
	AActor* AttachedActor;
protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override ;


	UPROPERTY(meta=(BindWidget))
	USizeBox* ParentSizeBox;
};
