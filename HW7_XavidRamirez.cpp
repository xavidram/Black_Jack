/*
Xavid Ramirez - 3/06/2015
Main file for the C++ based BlackJack game
*/
#include "BlackJack.h"


int main()
{
	// generate seed 
	srand(time(NULL));
	// initialize unparamaterized deck for game
	deck gamedeck;

	gamedeck.shuffle();

	
	gamedeck.PrintDeck();

	system("pause");
	system("cls");

	gamedeck.sort();

	gamedeck.PrintDeck();

	system("pause");
	system("CLS");
	// game functions
	BlackJack(gamedeck);
	system("pause");
	return 0;
}