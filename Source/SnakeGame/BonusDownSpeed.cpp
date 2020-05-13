// Fill out your copyright notice in the Description page of Project Settings.


#include "BonusDownSpeed.h"
#include "SnakeBase.h"

// Sets default values
ABonusDownSpeed::ABonusDownSpeed()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABonusDownSpeed::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(DestroyActorTimerHandle, this, &ABonusDownSpeed::DestroyActor, 10.0f, false);
}

// Called every frame
void ABonusDownSpeed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABonusDownSpeed::Interact(AActor* Interactor, bool bIsHead)
{
	auto Snake = Cast<ASnakeBase>(Interactor);
	if (bIsHead)
	{
		if (IsValid(Snake))
		{
			Snake->DecreaseSpeed();
			Destroy();
		}
	}
}

void ABonusDownSpeed::DestroyActor()
{
	Destroy();
}

