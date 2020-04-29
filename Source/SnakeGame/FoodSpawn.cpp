// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodSpawn.h"
#include "Food.h"
#include <ctime>
#include "SnakeBase.h"

// Sets default values
AFoodSpawn::AFoodSpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFoodSpawn::BeginPlay()
{
	Super::BeginPlay();
	AddFoodElement();
	
}

// Called every frame
void AFoodSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFoodSpawn::AddFoodElement(int ElementsNum /*= 1*/)
{
	srand(time(NULL));
	int x = -450 + (rand() % 90)*10;
	int y = -850 + (rand() % 170)*10;
	FVector NewLocation(x, y, 0);
	FTransform NewTransform(NewLocation);
	AFood* NewFoodElem = GetWorld()->SpawnActor<AFood>(FoodClass, NewTransform);
	
}



