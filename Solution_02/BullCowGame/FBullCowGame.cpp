#include "FBullCowGame.h"
#include <map>; 
#define TMap std::map

int FBUllCowGame::GetCurrentTry() const { return MyCurrentTry; }
int FBUllCowGame::GetMaxTries() const { 

	TMap<int32, int32> WordLengthToMaxTries{
		{3,5}, {4,6}, {5,7}, {6,8}
	};
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

using FString = std::string;
using int32 = int;


//Constructor
FBUllCowGame::FBUllCowGame() {
	Reset();
}

void FBUllCowGame::Reset() 
{
	MyCurrentTry = 0;

	const FString HIDDEN_WORD = "planet";
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

EWordStaus FBUllCowGame::CheckGuessValidity(std::string guess) const
{
	if (!IsIsogram(guess))
	{
		return EWordStaus::Not_Isogram;
	}
	else if (!IsLowerCase(guess))
	{
		//if guess isnt lower case
		return EWordStaus::Not_Lowercase;
	}
	else if (guess.length() != MyHiddenWord.length())
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
		bMyGameIsWon = true;
	}
	else {
		bMyGameIsWon = false;
	}
	return bullCowCount;
}

bool FBUllCowGame::IsIsogram(FString guess) const
{
	//Treat 0 and 1 letter words as isograms
	if (guess.length() >= 1)
	{


		//Setup map
		TMap<char, bool> letterSeen;
		for (auto letter : guess)
		{
			if (letterSeen[letter] == false)
			{
				letterSeen[letter] = true;
			}
			else if (letterSeen[letter] == true) {
				return false;
			}
		}

		return true;
	}

	return true; 
}

bool FBUllCowGame::IsLowerCase(FString guess) const
{
	for (auto letter : guess)
	{
		if (islower(letter))
		{
			return false;
		}
	}

	return true;
}
