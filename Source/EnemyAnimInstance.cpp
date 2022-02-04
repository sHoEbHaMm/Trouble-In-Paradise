// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAnimInstance.h"
#include "Enemy.h"

void UEnemyAnimInstance::NativeInitializeAnimation()
{
	if (pawn == nullptr)
	{
		pawn = TryGetPawnOwner();

		if (pawn)
		{
			Enemy = Cast<AEnemy>(pawn);
		}
	}
}

void UEnemyAnimInstance::UpdateAnimationProperties()
{
	if (pawn == nullptr)
	{
		pawn = TryGetPawnOwner();
	}

	if (pawn)
	{
		FVector speed = pawn->GetVelocity();
		FVector LateralSpeed = FVector(speed.X, speed.Y, 0.f);
		MovementSpeed = LateralSpeed.Size();

		Enemy = Cast<AEnemy>(pawn);
	}
}