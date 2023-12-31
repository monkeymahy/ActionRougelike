// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Canvas.h"
#include "GameFramework/HUD.h"
#include "SCross_Widget.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONROGUELIKE_API ASCross_Widget : public AHUD
{
	GENERATED_BODY()
protected:
    // 将被绘制在屏幕中心。
    UPROPERTY(EditDefaultsOnly)
    UTexture2D* CrosshairTexture;

public:
    // HUD绘制的主要调用。
    virtual void DrawHUD() override;
};
