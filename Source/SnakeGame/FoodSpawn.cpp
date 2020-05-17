// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodSpawn.h"
#include "Food.h"
#include <ctime>
#include "SnakeGameGameModeBase.h"
#include "Kismet/GameplayStatics.h"
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

	ASnakeGameGameModeBase* game_mode = Cast<ASnakeGameGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (game_mode)
	{
		game_mode->FoodSpawn = this;
	}
	
}

// Called every frame
void AFoodSpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFoodSpawn::AddFoodElement()
{
	srand(time(NULL));
	int x = -440 + (rand() % 16) * 55;
	int y = -825 + (rand() % 30) * 55;
	FVector NewLocation(x, y, 0);
	FTransform NewTransform(NewLocation);
	AFood* NewFoodElem = GetWorld()->SpawnActor<AFood>(FoodClass, NewTransform);
	
}



