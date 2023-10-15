// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class TPSGAMECPP_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void Shoot();

private:
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* GunMesh;
	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneRoot;

	UPROPERTY(EditAnywhere)
		UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere)
		UParticleSystem* ImpactParticleFX;

	UPROPERTY(EditAnywhere)
		float DistanceFire = 20000;
	UPROPERTY(EditAnywhere)
		float DamageBullet = 40;

	UPROPERTY(EditAnywhere)
		USoundBase* MuzzleSound;
	UPROPERTY(EditAnywhere)
		USoundBase* ImpactSound;

};
