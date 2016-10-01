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
	//UE_LOG(LogTemp, Warning, TEXT("SetupPlayerInputComponent Called"));
	//InputComponent->BindAction("Turret_ClockWise", IE_Pressed, this, &ATank::RotateCW);
	//InputComponent->BindAction("Turret_CounterclockWise", IE_Pressed, this, &ATank::RotateCCW);


	InputComponent->BindAxis("Rotate_Turret", this, &ATank::RotateTurret);
	InputComponent->BindAxis("Elevate_Turret", this, &ATank::ElevateBarrel);

	InputComponent->BindAxis("Move_Tank", this, &ATank::MoveTank);
	InputComponent->BindAxis("Roate_Tank", this, &ATank::RotateTank);
}

void ATank::MoveTank(float speed)
{
	//GetWorld()->DeltaTimeSeconds;
	if (!Turret) { return; }
	float Distance = GetWorld()->DeltaTimeSeconds * speed * MoviementSpeed;
	Tank->AddRelativeLocation(Tank->GetForwardVector() * Distance);

}

void ATank::RotateTank(float speed)
{
	if (!Turret) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds * speed * RotatationSpeed;
	//UE_LOG(LogTemp, Warning, TEXT("RotateTurrent Called"));
	Tank->AddRelativeRotation(FRotator(0.0, Rotation, 0.0));
}

void ATank::RotateTurret(float speed)
{
	if (!Turret) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds * speed * RotatationSpeed;
	//UE_LOG(LogTemp, Warning, TEXT("RotateTurrent Called"));
	Turret->AddRelativeRotation(FRotator(0.0, Rotation, 0.0));
}


void ATank::ElevateBarrel(float speed)
{
	if (!Barrel) { return; }
	float Rotation = GetWorld()->DeltaTimeSeconds * speed * RotatationSpeed;
	//UE_LOG(LogTemp, Warning, TEXT("RotateTurrent Called"));
	Barrel->AddRelativeRotation(FRotator(Rotation, 0.0, 0.0));
}


/*
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
*/

void ATank::SetTankChildActor(UChildActorComponent * TankFromBP)
{

	//UE_LOG(LogTemp, Warning, TEXT("SetTankChildActor Called"));
	if (!TankFromBP) { return; }
	Tank = TankFromBP;

}

void ATank::SetTurretChildActor(UChildActorComponent * TurretFromBP)
{
	
	//UE_LOG(LogTemp, Warning, TEXT("SetTurretChildActor Called"));
	if (!TurretFromBP) { return;  }
	Turret = TurretFromBP;

}

void ATank::SetBarrelChildActor(UChildActorComponent * BarrelFromBP)
{

	//UE_LOG(LogTemp, Warning, TEXT("SetBarrelChildActor Called"));
	if (!BarrelFromBP) { return; }
	Barrel = BarrelFromBP;

}

