// Fill out your copyright notice in the Description page of Project Settings.


#include "SWorldUserWidget.h"
#include <Kismet/GameplayStatics.h>
#include <Blueprint/WidgetLayoutLibrary.h>

void USWorldUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime) {
	Super::NativeTick(MyGeometry, InDeltaTime);

	FVector2D ScreenPosition;

	if (!IsValid(AttachedActor))
	{
		RemoveFromParent();
		
		return;
	}

	if (UGameplayStatics::ProjectWorldToScreen(GetOwningPlayer(), AttachedActor->GetActorLocation() + WordlOffset, ScreenPosition))
	{
		float Scale=UWidgetLayoutLibrary::GetViewportScale(this);

		ScreenPosition /= Scale;

		if (ParentSizeBox) {
			ParentSizeBox->SetRenderTranslation(ScreenPosition);
		}
	}
	
}