// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingPlatform.generated.h"

UCLASS()
class FIRSTPROJECT_API AFloatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingPlatform();

	/** MEsh for floating platform */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Floating Platform")
	class UStaticMeshComponent* FloatingPlatform;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = "true"))
	FVector StartPoint;

	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = "true"))
	FVector EndPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floating Platform")
	float InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floating Platform")
	FTimerHandle InterpTimer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floating Platform")
	bool bInterping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Floating Platform")
	float InterpTime;

	float Distance;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ToggleInterping();

	void SwapVectors(FVector& vec1, FVector& vec2);
};
