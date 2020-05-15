// Fill out your copyright notice in the Description page of Project Settings.


#include "DoobleFood.h"
#include "SnakeBase.h"

// Sets default values
ADoobleFood::ADoobleFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADoobleFood::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(DestroyActorTimerHandle, this, &ADoobleFood::DestroyActor, 10.0f, false);
}

// Called every frame
void ADoobleFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADoobleFood::Interact(AActor* Interactor, bool bIsHead)
{
	auto Snake = Cast<ASnakeBase>(Interactor);
	if (bIsHead)
	{
		if (IsValid(Snake))
		{
			Snake->AddSnakeElement();
			Snake->AddSnakeElement();
			Destroy();
		}
	}
}

void ADoobleFood::DestroyActor()
{
	Destroy();
}

