// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneRoot = CreateDefaultSubobject<USceneComponent>("ScenePivot");
	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>("GunMesh");

	RootComponent = SceneRoot;
	GunMesh->SetupAttachment(SceneRoot);

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::Shoot()
{
	UE_LOG(LogTemp, Display, TEXT("Sung Ban Bang bang !"));
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, GunMesh, TEXT("MuzzleSocket"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, GunMesh, TEXT("MuzzleFlashSocket"));

	APawn* OwnerOfGun = Cast<APawn>(GetOwner());
	if (!OwnerOfGun)return;
	AController* ControllerOfOwnerGun = OwnerOfGun->GetController();
	if (!ControllerOfOwnerGun)return;

	FVector LocationViewPl;
	FRotator RotationViewPl;

	ControllerOfOwnerGun->GetPlayerViewPoint(LocationViewPl, RotationViewPl);
	
	FVector EndForward = LocationViewPl + RotationViewPl.Vector() * DistanceFire;

	FHitResult HitBullet;
	FCollisionQueryParams BulletParams;
	BulletParams.AddIgnoredActor(this);
	BulletParams.AddIgnoredActor(GetOwner());
	bool IsHit = GetWorld()->LineTraceSingleByChannel(HitBullet, LocationViewPl, EndForward, ECC_GameTraceChannel1,BulletParams);

	if (IsHit)
	{
		FVector ShotDirection = -RotationViewPl.Vector();
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticleFX, HitBullet.Location, ShotDirection.Rotation());
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), ImpactSound, HitBullet.Location);

		AActor* HitActor = HitBullet.GetActor();
		if (HitActor)
		{
			FPointDamageEvent DamageEvent(DamageBullet, HitBullet, ShotDirection, nullptr);
			HitActor->TakeDamage(DamageBullet, DamageEvent, ControllerOfOwnerGun, this);
		}
	}

	
}

