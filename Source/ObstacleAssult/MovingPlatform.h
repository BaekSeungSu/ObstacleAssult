// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FVector StartLocation;

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector PlatformVelocity = FVector(100, 0, 0);
	UPROPERTY(EditAnywhere, Category="Moving Platform")
	float MovedDistance = 100;

	void MovePlatform(float Deltatime);
	void RotatePlatform(float Deltatime);

	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;
	
};
