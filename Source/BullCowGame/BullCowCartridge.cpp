// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine("welcome to bull cow game");
    //Hiddenword = TEXT("HOUSE");

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    this->ClearScreen();

    if(bGameOver == true)
    {
        PrintLine("Press enter to start new game");
        setupGame();
        return;
    }
    procesInput(Input);
    
} 


void UBullCowCartridge::setupGame()
{
    this->lives = 5;
	this->bGameOver = false;
    ClearScreen();
    PrintLine("welcome to bull cow game");
}

void UBullCowCartridge::procesInput(const FString& Input)
{
    if(Input.Len() == 0)
    {
        PrintLine("Please type in your guess");
        return;
    }


    if(Input == Hiddenword)
    {
        PrintLine("YAY you got it right,\npress enter to start new game");
        this->bGameOver = true;
        
    }

    else
    {
        lives--;
        const auto Temp = FString::Printf(TEXT("Wrong answer,you have %d lives left %s"),lives,*Hiddenword);
        PrintLine(Temp);
        if(lives == 0)
        {
            PrintLine("You have lost,\npress enter to start new game");
            this->bGameOver = true;
        }
    }
}