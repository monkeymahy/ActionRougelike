// Fill out your copyright notice in the Description page of Project Settings.


#include "SAction_Sprint.h"
#include "GameFrameWork/CharacterMovementComponent.h"
#include "SCharacter.h"

USAction_Sprint::USAction_Sprint()
{

}

void USAction_Sprint::StartAction_Implementation(AActor* Instigator)
{
	Super::StartAction_Implementation(Instigator);
	ASCharacter *Character = Cast<ASCharacter>(Instigator);
	Character->GetCharacterMovement()->MaxWalkSpeed += Bonus_Speed;
}

void USAction_Sprint::StopAction_Implementation(AActor* Instigator)
{
	Super::StopAction_Implementation(Instigator);
	ASCharacter* Character = Cast<ASCharacter>(Instigator);
	Character->GetCharacterMovement()->MaxWalkSpeed -= Bonus_Speed;
}

