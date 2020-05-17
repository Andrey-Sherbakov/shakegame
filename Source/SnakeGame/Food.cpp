// Fill out your copyright notice in the Description page of Project Settings.


#include "Food.h"
#include "SnakeBase.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FoodSpawn.h"
#include "SnakeGameGameModeBase.h"
#include "SnakeGameInstance.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

}

// Called when the game starts or when spawned
void AFood::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AFood::Interact(AActor* Interactor, bool bIsHead)
{
	auto Snake = Cast<ASnakeBase>(Interactor);
	if (bIsHead)
	{
		if (IsValid(Snake))
		{
			Snake->AddSnakeElement();
			ASnakeGameGameModeBase* game_mode = Cast<ASnakeGameGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
			USnakeGameInstance* game_instance = Cast<USnakeGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
			game_mode->FoodSpawn->AddFoodElement();
			game_instance->Scores = game_instance->Scores + 1;
			
			Destroy();
		}
	}
}


