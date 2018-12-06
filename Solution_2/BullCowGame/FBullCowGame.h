#pragma once
#include <string> 

class FBUllCowGame {
public:
	void Reset(); //TODO
	int GetMaxTries(); 
	int GetCurrentTry(); 
	bool IsGameWon(); 
	bool CheckGuessValidity(std::string);
   

private:
	int MyCurrentTry = 1; 
	int MyMaxTries = 5; 
};
