// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rifle.generated.h"

UCLASS()
class SIMPLESHOOTER_API ARifle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARifle();

	void PullTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

UPROPERTY(VisibleAnywhere)
USceneComponent* Root;

UPROPERTY(VisibleAnywhere)
USkeletalMeshComponent* Mesh;

UPROPERTY(EditAnywhere, category = "Effects")
UParticleSystem* MuzzleFlash;

UPROPERTY(EditAnywhere, category = "Effects")
USoundBase* MuzzleSound;

UPROPERTY(EditAnywhere, category = "Effects")
USoundBase* ImpactSound;

UPROPERTY(EditAnyWhere, category = "Range")
float MaxRange = 2750; 
 
UPROPERTY(EditAnywhere, category = "Effects")
UParticleSystem* ImpactEffect;

UPROPERTY(EditAnywhere, category = "Damage")
float Damage = 10;

bool GunTrace(FHitResult &Hit, FVector& ShotDirection);

AController* GetOwnerController() const;



};
