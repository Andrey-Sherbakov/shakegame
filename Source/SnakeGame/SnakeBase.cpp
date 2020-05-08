// Fill out your copyright notice in the Description page of Project Settings.


#include "SnakeBase.h"
#include "SnakeElementBase.h"
#include "Interactable.h"
#include "Food.h"
#include "BonusUpSpeed.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include <ctime>

// Sets default values
ASnakeBase::ASnakeBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ElementSize = 100.f;
	MovementSpeed = 10.f;
	LastMovementDirection = EMovementDirection::DOWN;
}

// Called when the game starts or when spawned
void ASnakeBase::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickInterval(MovementSpeed);
	AddSnakeElement(4);
	AddFoodElement();
	GetWorld()->GetTimerManager().SetTimer(BonusTimerHandle, this, &ASnakeBase::AddBonus, 5.0f, true, 5.0f);
}

// Called every frame
void ASnakeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();

}

void ASnakeBase::AddSnakeElement(int ElementsNum)
{
	for (int i = 0; i < ElementsNum; ++i)
	{
		FVector NewLocation(SnakeElements.Num() * ElementSize, 0, 0);
		FTransform NewTransform(NewLocation);
		ASnakeElementBase* NewSnakeElem = GetWorld()->SpawnActor<ASnakeElementBase>(SnakeElementClass, NewTransform);
		NewSnakeElem->SnakeOwner = this;
		int32 ElemIndex = SnakeElements.Add(NewSnakeElem);
		if (ElemIndex == 0)
		{
			NewSnakeElem->SetFirstElementType();
		}
	}
}

void ASnakeBase::AddFoodElement()
{
	srand(time(NULL));
	int x = -450 + (rand() % 9) * 100;
	int y = -850 + (rand() % 17) * 100;
	FVector NewLocation(x, y, 0);
	FTransform NewTransform(NewLocation);
	AFood* NewFoodElem = GetWorld()->SpawnActor<AFood>(FoodClass, NewTransform);
}

void ASnakeBase::Move()
{
	FVector MovementVector(ForceInitToZero);

	switch (LastMovementDirection)
	{
	case EMovementDirection::UP:
		MovementVector.X += ElementSize;
		break;
	case EMovementDirection::DOWN:
		MovementVector.X -= ElementSize;
		break;
	case EMovementDirection::LEFT:
		MovementVector.Y += ElementSize;
		break;
	case EMovementDirection::RIGHT:
		MovementVector.Y -= ElementSize;
		break;
	}

	SnakeElements[0]->ToggleColision();
	SnakeElements[0]->MeshComponent->SetVisibility(true);

	for (int i = SnakeElements.Num() - 1; i > 0; i--)
	{
		auto CurrentElement = SnakeElements[i];
		auto PrevElement = SnakeElements[i - 1];
		FVector PrevLocation = PrevElement->GetActorLocation();
		CurrentElement->SetActorLocation(PrevLocation);
		SnakeElements[i]->MeshComponent->SetVisibility(true);
	}

	SnakeElements[0]->AddActorWorldOffset(MovementVector);
	SnakeElements[0]->ToggleColision();

}

void ASnakeBase::SnakeElementOverlap(ASnakeElementBase* OverlappedElement, AActor* Other)
{
	if (IsValid(OverlappedElement))
	{
		int32 ElemIndex;
		SnakeElements.Find(OverlappedElement, ElemIndex);
		bool bIsFirst = ElemIndex == 0;
		IInteractable* InteractableInterface = Cast<IInteractable>(Other);
		if (InteractableInterface)
		{
			InteractableInterface->Interact(this, bIsFirst);
		}
	}
}

void ASnakeBase::IncreaseSpeed()
{
	MovementSpeed = MovementSpeed - 0.01;
	SetActorTickInterval(MovementSpeed);
}

void ASnakeBase::DecreaseSpeed()
{
	auto a = GetActorTickInterval() + 0.1;
	SetActorTickInterval(a);
}

void ASnakeBase::AddBonus()
{
	srand(time(NULL));
	int x = -450 + (rand() % 9) * 100;
	int y = -850 + (rand() % 17) * 100;
	FVector NewLocation(x, y, 0);
	FTransform NewTransform(NewLocation);
	ABonusUpSpeed* NewBonus = GetWorld()->SpawnActor<ABonusUpSpeed>(BonusUpSpeedClass, NewTransform);
}

