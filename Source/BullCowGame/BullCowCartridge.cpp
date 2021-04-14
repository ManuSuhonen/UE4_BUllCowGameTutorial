// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    //Hiddenword = TEXT("HOUSE");

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    this->ClearScreen();

    if(bGameOver == true)
    {
        PrintLine("presss enter to start new game");
    }

    if(Input == Hiddenword)
    {
        PrintLine("YAY YOU GOT IT prooooper");
        this->bGameOver = true;
        setupGame();
    }

    else
    {
        lives--;
        const auto Temp = FString::Printf(TEXT("WRONG ANSWER,you have %d lives left %s"),lives,*Hiddenword);
        PrintLine(Temp);
        if(lives == 0)
        {
            PrintLine("you have lost, press enter to start new game");
            this->bGameOver = true;
            setupGame();
        }
    }
} 


void UBullCowCartridge::setupGame()
{
    this->lives = 5;
	this->bGameOver = false;
    ClearScreen();
    PrintLine("welcome to bull cow game");
}


