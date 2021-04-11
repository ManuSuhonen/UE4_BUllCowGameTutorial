// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

#define TEST 123

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:

	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Hidden Word")
	FString Hiddenword;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Manu")
	TArray<int32> Intvec;

	// Your declarations go below!
	private:
	
};


