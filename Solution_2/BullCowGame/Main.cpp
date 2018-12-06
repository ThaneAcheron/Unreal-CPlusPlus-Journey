//Libaries
#include <iostream>
#include <string>
#include "FBullCowGame.h"

//Namespaces
using namespace std;

//Methods
void PrintIntro();
string GetGuess();
void PlayGame();
bool AskToPlayAgain();

FBUllCowGame BCGAME;

void main() {
	bool bPlayAgain = false;

	do 
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain == true);
}

void PlayGame() {

	int maxtries = BCGAME.GetMaxTries();
	cout << maxtries << endl;

	string guess = ""; 
	
	for (int i = 1; i <= maxtries; i++)
	{
		 guess = GetGuess();
		 cout << "\n" << guess << "\n";
	}
}

string GetGuess() {

	cout << "Try " << BCGAME.GetCurrentTry() << " Enter your Guess:";
	string guess = "";
	getline(cin, guess);

	return guess;
}

void PrintIntro() {

	constexpr int WORD_LENGTH = 5;

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