// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Shooter.generated.h"

class ARifle;
UCLASS()
class SIMPLESHOOTER_API AShooter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UFUNCTION(BlueprintPure)
	bool IsDead() const;

	UFUNCTION(BlueprintPure)
	float GetHealthPercent() const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const &DamageEvent, class AController *EventInstigator, AActor *DamageCauser) override;

	void Shoot();
	
private:
	// functions
	void MoveForward(float AxisValue);
	void MoveRight(float Value);
	void LookUpRate(float RateValue);
	void LookRightRate(float RateValue);
	//TODO Rotate character
	//void Rotate(FRotator RotateValue);
	
	//variables
	UPROPERTY(EditAnywhere)
	float RotationRate = 10;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ARifle> RifleClass;

	UPROPERTY()
	ARifle* Rifle;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere)
	float Health;


};
