// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
//#include "HiddenWordList.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    

    Super::BeginPlay();

    const FString WordListPath = FPaths::ProjectContentDir() / TEXT("WordLists/isogram_word_list.txt");
    FFileHelper::LoadFileToStringArray(Result, *WordListPath);

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
    
    
    this->lives = 5;
	this->bGameOver = false;
    level = 4;
    Hiddenword = getValidWord();
    ClearScreen();
    PrintLine("Welcome to bull cow game.");
    PrintLine(TEXT("Please guess a %i letter word.\nYou have %i lives left "),Hiddenword.Len(),lives);

}

void UBullCowCartridge::procesInput(const FString& Input)
{
    //PrintLine(Input);
    if(this->bGameOver == true)
    {
        this->setupGame();
    }

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

    if(Input.Len() != Hiddenword.Len())
    {
        PrintLine(TEXT("Please type in %i characters"),Hiddenword.Len());
        return;
    }

    if(Input == Hiddenword)
    {
        

        if(this->level < 7)
        {
            level++;
            nextLevel();
        }
        else
        {
            PrintLine("Yay you got it all correct!!\nPress enter to start new game");
            this->bGameOver = true;
        }
    }

    else
    {
        lives--;
        PrintLine(TEXT("Wrong answer,you have %i lives left"),lives);

        bullCowLogic(Input);

        if(lives == 0)
        {
            PrintLine("You have lost,\nPress enter to start new game");
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


FString UBullCowCartridge::getValidWord()
{
    TArray<FString> tempstrarr;
    for(auto t: Result)
    {
        if(t.Len() == level)
        {
            tempstrarr.Emplace(t);
        }
    }

    int32 index = FMath::RandRange(0, tempstrarr.Num()-1);
    UE_LOG(LogTemp, Display, TEXT("loaded random name from file: %s"),*(tempstrarr[index]));
    return tempstrarr[index];
}


void UBullCowCartridge::nextLevel()
{
    Hiddenword = getValidWord();
    ClearScreen();
    PrintLine(TEXT("Please guess a %i letter word.\nYou have %i lives left "),Hiddenword.Len(),lives);
}

void UBullCowCartridge::bullCowLogic(const FString& Input)
{
    if(lives != 0)
        {
            int32 bulls = 0;
            int32 cows = 0;

            for (size_t i = 0; i < Input.Len(); i++)
            {
                if(Input[i] == Hiddenword[i]) 
                {
                    bulls++;
                }
            }

            for (size_t i = 0; i < Hiddenword.Len(); i++)
            {
                for (size_t i2 = 0; i2 < Input.Len(); i2++)
                {
                    if(i == i2)continue;

                    if(Hiddenword[i] == Input[i2])
                    {
                        cows++;
                    }
                }
            }

            PrintLine(TEXT("you have %i bulls and %i cows"),bulls, cows);
        }
}