// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "Gun.h"
#include "ShooterGameModeBase.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	CameraTPS = CreateDefaultSubobject<UCameraComponent>("CameraFollow");
	SpringArm->SetupAttachment(RootComponent);
	CameraTPS->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	Gun->SetOwner(this);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("GunSocket"));
	Health = MaxHealth;
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateYawAim(DeltaTime);
}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AShooterCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AShooterCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAction(TEXT("Shoot"), IE_Pressed, this, &AShooterCharacter::Shoot);
}

float AShooterCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float DamageReceive = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageReceive = FMath::Min(Health, DamageReceive);
	Health -= DamageReceive;
	UE_LOG(LogTemp, Display, TEXT("Health con lai la %f"), Health);
	if (Health == 0)
	{
		AShooterGameModeBase* ShGameMode = Cast<AShooterGameModeBase>(GetWorld()->GetAuthGameMode());
		if (ShGameMode)
		{
			ShGameMode->PawnKilled(this);
		}
		SetActorEnableCollision(false);
		DetachFromControllerPendingDestroy();
	}
	return 0;
}

void AShooterCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector() * Value);
}

void AShooterCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector() * Value);
}


void AShooterCharacter::UpdateYawAim(float DeltaT)
{
	FRotator YawAimFoward = FMath::RInterpTo(GetActorRotation(), GetControlRotation(),DeltaT,SpeedTransToAim);
	
	SetActorRotation(FRotator(GetActorRotation().Pitch, YawAimFoward.Yaw, GetActorRotation().Roll));
}



void AShooterCharacter::Shoot()
{
	Gun->Shoot();
}

bool AShooterCharacter::isAlive()
{
	bool bAlive = Health > 0;
	return bAlive;
}

float AShooterCharacter::GetHealthPercent()
{
	float Percent = Health / MaxHealth;
	return Percent;
}

