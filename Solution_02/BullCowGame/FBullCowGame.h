#pragma once
#include <string> 

using int32 = int; 
using FString = std::string;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStaus {
Invalid,
Ok,
Not_Isogram,
Wrong_Length,
Not_Lowercase
};

enum class EResetStatus {
 Ok,
 Not_isogram
};

class FBUllCowGame {
public:

	FBUllCowGame(); //Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	int32 GetHiddenWordLength() const;

	void Reset(); //TODO
	EWordStaus CheckGuessValidity(std::string) const;

	// provide a method for counting bulls and cows, and increasing turn number assumes valid guess
	FBullCowCount SumbitGuess(FString);

private:
 //Construct Inilitialisation
	int MyCurrentTry;
	int MyMaxTries;
	bool bMyGameIsWon;
	FString MyHiddenWord;
};
