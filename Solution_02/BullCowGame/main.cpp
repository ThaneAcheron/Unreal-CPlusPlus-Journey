/*
Thia is the console executable that makes use of the bullcow class, this acts as the view in a mvc pattern asn is responsible for all user interaction. for game logic see the FBullCowGame class.
*/

//Libaries
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

//Namespaces
using namespace std;

//Methods
void PrintIntro();
string GetValidGuess();
void PlayGame();
bool AskToPlayAgain();
FText CheckGuessValidity(FText);

FBUllCowGame BCGAME;

int main() {
	bool bPlayAgain = false;

	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain == true);
}

void PlayGame() {
	BCGAME.Reset();

	int32 maxtries = BCGAME.GetMaxTries();
	cout << maxtries << endl;

	// TODO add a game summary
	string guess = "";

	while (!BCGAME.IsGameWon() && BCGAME.GetCurrentTry <= maxtries)
	{
		guess = GetValidGuess(); //TODO get valid guess

		//submit valid guess to the game
		FBullCowCount BullCowCount = BCGAME.SumbitGuess(guess);
		std::cout << "Bulls - " << BullCowCount.Bulls;
		std::cout << "  Cows - " << BullCowCount.Cows;
		//print number of bulls and cowsa

		cout << "\n" << guess << "\n";
	}
}


string GetValidGuess() {

	EWordStaus status = EWordStaus::Invalid;
	string guess = "";

	do
	{
		cout << "Your Try: " << BCGAME.GetCurrentTry() << " Enter your Guess:";
		getline(cin, guess);
	    status = BCGAME.CheckGuessValidity(guess);

		switch (status)
		{
		case EWordStaus::Wrong_Length:
			cout << "Please enter a " << BCGAME.GetHiddenWordLength() << " letter word. \n";
			break;
		case EWordStaus::Not_Isogram:
			cout << "Please enter a word without repeating letters";
			break;
		case EWordStaus::Not_Lowercase:
			cout << "Please enter all lowercase letters";
			break;
		default:
			break;
		}
	} while (status != EWordStaus::Ok);

	return guess;
}

void PrintIntro() {

	int WORD_LENGTH = BCGAME.GetHiddenWordLength();

	cout << "Welcome to bulls and cows, a fun word game." << endl;
	cout << "Can you guess the word I'm thinking? It's " << WORD_LENGTH;
	cout << " letters long\n";
	return;
}

bool AskToPlayAgain() {

	string response = "";

	cout << "Do you want to play again? [Y/N]";
	getline(cin, response);

	return response[0] == 'y' || response == "Y";
}