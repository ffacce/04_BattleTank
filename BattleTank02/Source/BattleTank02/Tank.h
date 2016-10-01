// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK02_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTankChildActor(UChildActorComponent * TankFromBP);
	
	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetTurretChildActor(UChildActorComponent * TurretFromBP);

	UFUNCTION(BlueprintCallable, Category = Tank)
	void SetBarrelChildActor(UChildActorComponent * BarrelFromBP);

private:
	// Rotate turret at speed 
	
	//void RotateCW(); 
	//void RotateCCW();
	void MoveTank(float speed);
	void RotateTank(float speed);
	UChildActorComponent *Tank = nullptr;


	void RotateTurret(float speed);
	UChildActorComponent *Turret = nullptr;


	void ElevateBarrel(float speed);
	UChildActorComponent *Barrel = nullptr;

	UPROPERTY(EditAnywhere)
	float RotatationSpeed = 120.f;

	UPROPERTY(EditAnywhere)
	float MoviementSpeed = 120.f;
	
};
