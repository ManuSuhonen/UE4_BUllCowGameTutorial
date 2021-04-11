// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    //Hiddenword = TEXT("HOUSE");

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    int32 t = TEST;
    if(Input == Hiddenword)
    {
        PrintLine("YAY YOU GOT IT RIGHT");
    }

    else
    {
        const auto Temp = FString::Printf(TEXT("NOPE WRONG ANSWER %s"),*Hiddenword);
        PrintLine(Temp);


    }
    
} 


