// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();

	FString Name = GetName();


	UE_LOG(LogTemp, Display, TEXT("BeginPlay : %s"), *Name);
}


// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	// Move platform forwads
		// Get current location
	FVector CurrentLocation = GetActorLocation();
		// Add vector to that location
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		// Set the location
	SetActorLocation(CurrentLocation);
	// Send platform back if gone too far
		// Check how far we've moved
	FVector::Dist(StartLocation, CurrentLocation);
	float DistanceMoved = FVector::Dist(StartLocation, CurrentLocation);
		// Reverse direction of motion if gone too far
	if(DistanceMoved > MovedDistance){
		FString Name = GetName();
		float OverShoot = DistanceMoved - MovedDistance;
		UE_LOG(LogTemp, Display, TEXT("%s is OverShoot : %f"), *Name, OverShoot);
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MovedDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
}

void AMovingPlatform::RotatePlatform(float Deltatime)
{
	UE_LOG(LogTemp, Display, TEXT("%s Rotating..."),*GetName());
}
