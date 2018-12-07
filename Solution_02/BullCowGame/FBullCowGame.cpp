#include "FBullCowGame.h"
int FBUllCowGame::GetCurrentTry() const { return MyCurrentTry; }
int FBUllCowGame::GetMaxTries() const { return MyMaxTries; }

using FString = std::string;
using int32 = int;


//Constructor
FBUllCowGame::FBUllCowGame() {
	Reset();
}

void FBUllCowGame::Reset() 
{
	constexpr int32 MAX_TRIES = 8;
	MyCurrentTry = MAX_TRIES;
	MyMaxTries = 8;

	const FString HIDDEN_WORD = "antman";
	MyHiddenWord = HIDDEN_WORD;
	bMyGameIsWon = false;
	return;
}

bool FBUllCowGame::IsGameWon() const
{

	return bMyGameIsWon;
}

int32 FBUllCowGame::GetHiddenWordLength() const
{
	return  MyHiddenWord.length();
}

EWordStaus FBUllCowGame::CheckGuessValidity(std::string result) const
{
	if (false)
	{
		return EWordStaus::Not_Isogram;
	}
	else if (false)
	{
		//if guess isnt lower case
		return EWordStaus::Not_Lowercase;
	}
	else if (result.length() != MyHiddenWord.length())
	{
		return EWordStaus::Wrong_Length;
	}
	else {
		return EWordStaus::Ok;
	}
}

//recieves a valid guess, increments turn, returns count
FBullCowCount FBUllCowGame::SumbitGuess(FString guess)
{
	//increament turn number
	MyCurrentTry++;
	//setup a return variable 
	FBullCowCount bullCowCount;

	//loop through all the letters in the game
	//compare letters again the hidden word 
	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 MGWChar = 0; MGWChar < HiddenWordLength; MGWChar++)
	{
		for (int32 HWCHAR = 0; HWCHAR < HiddenWordLength; HWCHAR++)
		{
			if (MyHiddenWord[MGWChar] == guess[HWCHAR])
			{
				if (MGWChar == HWCHAR)
				{
					bullCowCount.Bulls++;
				}
				else {
					bullCowCount.Cows++;
				}
			}

		}
	}

	if (bullCowCount.Bulls == HiddenWordLength)
	{
		bMyGameIsWon = true
	}
	else {
		bMyGameIsWon = false;
	}
	return bullCowCount;
}
