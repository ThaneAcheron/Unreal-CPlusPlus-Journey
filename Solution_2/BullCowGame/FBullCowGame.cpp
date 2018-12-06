#include "FBullCowGame.h"
int FBUllCowGame::GetCurrentTry() { return MyCurrentTry; }
int FBUllCowGame::GetMaxTries() { return MyMaxTries; }

void FBUllCowGame::Reset()
{
	return;
}

bool FBUllCowGame::IsGameWon()
{
	return false;
}

bool FBUllCowGame::CheckGuessValidity(std::string)
{
	return false;
}
