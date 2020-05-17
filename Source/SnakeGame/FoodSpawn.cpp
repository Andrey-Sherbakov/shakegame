// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodSpawn.h"
#include "Food.h"
#include <ctime>
#include "SnakeGameGameModeBase.h"
#include "SnakeGameInstance.h"
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
	USnakeGameInstance* game_instance = Cast<USnakeGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	int32 Scores = game_instance->Scores;
	int x = -440 + (rand() % 16) * 55;
	int y = -825 + (rand() % 30) * 55;
	if (Scores >= 5 && Scores <= 15)
	{
		if (x == -275 || x == 275)
		{
			x = x + 55;
		}
	}
	if (Scores >= 15)
	{
		if (x == -275 || x == 275)
		{
			x = x + 55;
		}
		if (y == -770 || y == 770)
		{
			y = y + 55;
		}
	}	
	FVector NewLocation(x, y, 0);
	FTransform NewTransform(NewLocation);
	AFood* NewFoodElem = GetWorld()->SpawnActor<AFood>(FoodClass, NewTransform);
}



