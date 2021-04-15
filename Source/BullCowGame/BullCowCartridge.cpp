// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
//#include "HiddenWordList.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    

    Super::BeginPlay();
    setupGame();
   // PrintLine("welcome to bull cow game");
   // Hiddenword = WordList[FMath::RandRange(0, WordList.Num())];
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
    FJsonSerializableArray Result;
    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordLists/isogram_word_list.txt");
    FFileHelper::LoadFileToStringArray(Result, *WordListPath);

    int32 index = FMath::RandRange(0, Result.Num()-1);
    UE_LOG(LogTemp, Display, TEXT("loaded random name from file: %s"),*(Result[index]));
    Hiddenword = Result[index];
    this->lives = 5;
	this->bGameOver = false;
    ClearScreen();
    PrintLine("welcome to bull cow game");
}

void UBullCowCartridge::procesInput(const FString& Input)
{
    PrintLine(Input);

    if(Input.Len() == 0)
    {
        PrintLine("Please type in your guess");
        return;
    }

    if(!isIsoGram(Input))
    {
        PrintLine("input isn't an isogram");
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
        const auto Temp = FString::Printf(TEXT("Wrong answer,you have %i lives left %s"),lives,*Hiddenword);
        PrintLine(Temp);
        if(lives == 0)
        {
            PrintLine("You have lost,\npress enter to start new game");
            this->bGameOver = true;
        }
    }
}


bool UBullCowCartridge::isIsoGram(const FString& Input) const
{
    auto temp = Input.ToLower();

    for (size_t i = 0; i < temp.Len()-1; i++)
    {
        for (size_t i2 = i+1; i2 < temp.Len(); i2++)
        {
            if(temp[i] == temp[i2])
            {
                return false;
            }
        }
    }

    
    return true;
}