// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "ShooterCharacter.generated.h"

class AGun;
UCLASS()
class TPSGAMECPP_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)override;

	void Shoot();

	UFUNCTION(BlueprintPure)
	bool isAlive();

	UFUNCTION(BlueprintPure)
		float GetHealthPercent();

private:
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* CameraTPS;

	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* SpringArm;

	void MoveForward(float Value);
	void MoveRight(float Value);

	

	UPROPERTY(EditAnywhere)
		TSubclassOf<AGun> GunClass;

	AGun* Gun;

	float Health;
	UPROPERTY(EditAnywhere)
		float MaxHealth = 100;

	UPROPERTY(EditAnywhere)
		float SpeedTransToAim = 5;

	void UpdateYawAim(float DeltaT);

};
