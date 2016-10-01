// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank02.h"
#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATank::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	UE_LOG(LogTemp, Warning, TEXT("SetupPlayerInputComponent Called"));
	InputComponent->BindAction("Turret_ClockWise", IE_Pressed, this, &ATank::RotateCW);
	InputComponent->BindAction("Turret_CounterclockWise", IE_Pressed, this, &ATank::RotateCCW);
}

void ATank::RotateCW()
{
	UE_LOG(LogTemp, Warning, TEXT("RotateTurrent Called"));
	Turret->SetRelativeRotation(FRotator(0.0, 45.F, 0.0));
}


void ATank::RotateCCW()
{
	UE_LOG(LogTemp, Warning, TEXT("RotateTurrent Called"));
	Turret->SetRelativeRotation(FRotator(0.0, -45.F, 0.0));
}


void ATank::SetTurretChildActor(UChildActorComponent * TurrentFromBP)
{
	UE_LOG(LogTemp, Warning, TEXT("SetTurretChildActor Called"));

	Turret = TurrentFromBP;

}

