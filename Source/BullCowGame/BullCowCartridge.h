// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:

	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;

	void setupGame();
	void procesInput(const FString& Input);
	bool isIsoGram(const FString& Input) const;
	void nextLevel();
	FString getValidWord();

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Hidden Word")
	FString Hiddenword;

	// UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="test vector")
	// TArray<int32> test_vector;

	// Your declarations go below!
	private:
	int32 lives = 5;
	int32 level = 4;
	bool bGameOver;
	FJsonSerializableArray Result;
};


