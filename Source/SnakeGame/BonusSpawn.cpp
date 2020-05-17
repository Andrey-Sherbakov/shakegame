// Fill out your copyright notice in the Description page of Project Settings.


#include "BonusSpawn.h"
#include "BonusUpSpeed.h"
#include "BonusDownSpeed.h"
#include "DoobleFood.h"
#include <ctime>
#include "SnakeBase.h"

// Sets default values
ABonusSpawn::ABonusSpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABonusSpawn::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(BonusTimerHandle, this, &ABonusSpawn::AddBonus, 10.0f, true, 10.0f);
}

// Called every frame
void ABonusSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABonusSpawn::AddBonus()
{
	srand(time(NULL));
	int RandomBonus = rand() % 3;
	int x = -440 + (rand() % 16) * 55;
	int y = -825 + (rand() % 30) * 55;
	FVector NewLocation(x, y, 0);
	FTransform NewTransform(NewLocation);
	if (RandomBonus == 0)
	{
		ABonusUpSpeed* NewBonusUS = GetWorld()->SpawnActor<ABonusUpSpeed>(BonusUpSpeedClass, NewTransform);
	}
	if (RandomBonus == 2)
	{
		ABonusDownSpeed* NewBonusDS = GetWorld()->SpawnActor<ABonusDownSpeed>(BonusDownSpeedClass, NewTransform);
	}
	if (RandomBonus == 1)
	{
		ADoobleFood* NewBonusDF = GetWorld()->SpawnActor<ADoobleFood>(DoubleFoodClass, NewTransform);
	}
}

