// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Main.h"

void UMainAnimInstance::NativeInitializeAnimation()
{
	if (pawn == nullptr)
	{
		pawn = TryGetPawnOwner();

		if (pawn)
		{
			Main = Cast<AMain>(pawn);
		}
	}
}

void UMainAnimInstance::UpdateAnimationProperties()
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

		bIsinAir = pawn->GetMovementComponent()->IsFalling();

		if (Main == nullptr)
		{
			Main = Cast<AMain>(pawn);
		}
	}
}