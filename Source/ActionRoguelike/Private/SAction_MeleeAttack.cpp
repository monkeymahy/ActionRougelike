// Fill out your copyright notice in the Description page of Project Settings.


#include "SAction_MeleeAttack.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

USAction_MeleeAttack::USAction_MeleeAttack()
{
	AttackAnimDelay = 0.1f;
	HandSocketName = "Muzzle_01";
}

void USAction_MeleeAttack::AttackDelay_Elapsed(ACharacter* InstigatorCharacter)
{

}

void USAction_MeleeAttack::StartAction_Implementation(AActor* Instigator)
{
	Super::StartAction_Implementation(Instigator);

	ACharacter* Character = Cast<ACharacter>(Instigator);
	if (Character) {
		Character->PlayAnimMontage(AttackAnim);

		UGameplayStatics::SpawnEmitterAttached(AttackEffect, Character->GetMesh(), HandSocketName, FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::SnapToTarget);

		FTimerHandle TimerHandle_AttackDelay;
		FTimerDelegate Delegate;
		Delegate.BindUFunction(this, "AttackDelay_Elapsed", Character);

		GetWorld()->GetTimerManager().SetTimer(TimerHandle_AttackDelay, Delegate, AttackAnimDelay, false);
	}

}

