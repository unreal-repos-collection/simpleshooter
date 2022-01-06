// Fill out your copyright notice in the Description page of Project Settings.


#include "Shooter.h"
#include "Rifle.h"
#include "Components/CapsuleComponent.h"
#include "SimpleShooterGameModeBase.h"


// Sets default values
AShooter::AShooter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void AShooter::BeginPlay()
{
	Super::BeginPlay();
	
	Health = MaxHealth;
	
	Rifle = GetWorld()->SpawnActor<ARifle>(RifleClass);

	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Rifle->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Rifle->SetOwner(this);
}

bool AShooter::IsDead() const
{
	return Health <= 0;
}

float AShooter::GetHealthPercent() const
{
	return Health / MaxHealth;
}

// Called every frame
void AShooter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	//controller inputs
	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, &AShooter::LookRightRate);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AShooter::LookUpRate);


	//keyboard/mouse controls
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AShooter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AShooter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &ACharacter::Jump);
	
	PlayerInputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &AShooter::Shoot);
	//TODO Rotate character
	// PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AShooter::Rotate);		

	
}

float AShooter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) 
{
	float DamageApplied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageApplied = FMath::Min(Health, DamageApplied);
	Health -= DamageApplied;
	UE_LOG(LogTemp, Warning, TEXT("Health left %f"), Health);
	
	if (IsDead())
	{
		ASimpleShooterGameModeBase* GameMode = GetWorld()->GetAuthGameMode<ASimpleShooterGameModeBase>();
		
		if (GameMode != nullptr)
		{
			GameMode->PawnKilled(this);
		}
		
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		
	
	}
	
	
	return DamageApplied;
	
}

void AShooter::MoveForward(float AxisValue) 
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AShooter::MoveRight(float Value) 
{
	AddMovementInput(GetActorRightVector() * Value);
}

void AShooter::LookUpRate(float RateValue) 
{
	AddControllerPitchInput(RateValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AShooter::LookRightRate(float RateValue) 
{
	AddControllerYawInput(RateValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void AShooter::Shoot() 
{
	Rifle->PullTrigger();
}
//TODO Rotate character

// void AShooter::Rotate(FRotator RotateValue) 
// {
// 	AddMovementInput(GetActor().Yaw * RotateValue);
// }




