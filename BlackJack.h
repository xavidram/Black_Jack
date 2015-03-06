/*
Xavid Ramirez - 3/06/2015
This is a C++ based blackjack game.
*/
#include "DeckOfCards_Class.h"

void IntroDisplay()
{
	// ans variable will hold user input answer
	char ans = ' ';
	// this function is the intro to the game. 
	cout << "===---Welcome to the Consol Black Jack Game---===" << endl;
	cout << "Would you like to read the rules of the game?(y/n)"; cin >> ans; cout << endl << endl;

	// if the user does not enter y for yes or n for no then it will
	// keep asking them to input a correct answer.
	while (ans != 'y' && ans != 'n')
	{
		cin.clear();
		cin.ignore(10000, '/n');
		cout << "You have entered an invalid answer, type y for yes or n for no: "; cin >> ans;
	}

	// if they answer yes then the instructions for the game are displayed
		if (ans == 'y')
		{

			cout << "The game is simple, you will be dealt two cards.";
			cout << "Your goal is to reach the number 21 with the cards you receive";
			cout << "1 is an Ace which has a value of 1 or 11. All other cards have default value.";
			cout << "You will be prompted if you would like another card, it is your decision to take it or not.";
			cout << "Take as many cards are you need to get 21, if you go over you loose, you can fold if don't think you wil get to 21" << endl;
			cout << "Good Luck!" << endl << endl;
			cout << "======================================" << endl << endl;
			system("pause");
		}
		// if they say no then we continue with the game. 
		else if (ans == 'n')
		{
			cout << "Then lets begin!" << endl << endl;
			cout << "======================================" << endl << endl;
			system("pause");
		}

		// since there is so much text, this will clear the txt on the terminal.
		system("CLS");

}



void midgame(deck gamedeck)
{
	// ans will hold user input answer
	char ans = ' ';
	// current cards holds all the cards dealt to the user.
	card currentcards[100];

	cout << "Here are you two cards:" << endl;
	currentcards[0] = gamedeck.dealCardFromTop();
	currentcards[1] = gamedeck.dealCardFromTop();

	// cards holds the number of cards currently dealt
	int cards = 2;
	//total holds the total value of all the cards
	int total = 0;
	int i = 0;
	// this will sum up the cards for the first trial
	for (i; i < cards; i++)
	{
		currentcards[i].printCard();
		cout << endl;
		total += currentcards[i].number;
	}
	
	//print out the total of the cards and if they go over 20 then game ends
	cout << "Your current card total is " << total << endl << endl;
	if (total > 21)
	{
		cout << "So sorry...You are very unlucky from the start." << endl << endl;
	}
	// if they manage to get 21 on first deal then this is prompted and game ends.
	else if (total == 21)
	{
		cout << "Well good thing we didn't bet any money huh?" << endl;
		cout << "Thank you for playing." << endl;
	}
	// as long as they keep playing then this loop continues
	while(true)
	{
		// if they go over 21 then game ends. 
		if (total > 21)
		{
			cout << "Sorry but you have lost! Thanks for playing!" << endl << endl;
			break;
		}

		cout << "Would you like another card?(y/n) "; cin >> ans; cout << endl;
		// if they havenet reached 21 or gone over then keep asking them if they want another card.
		// then basically repeat what we did for the first trial. 
		if (ans == 'y')
		{
			currentcards[i] = gamedeck.dealCardFromTop();
			cards++;
			cout << "Here is the new card: "; currentcards[i].printCard(); cout << endl;
				
				for (i; i < cards; i++)
				{
					currentcards[i].printCard();
					cout << endl;
					total += currentcards[i].number;
				}

				cout << "Your current card total is " << total << endl << endl;
				cout << "===============================" << endl;
		}
		// if they answer no then game ends.
		else if (ans == 'n')
		{
			cout << "Thank you for playing!" << endl << endl;
			break;
		}
		// if they reach 21 then they win and game ends. 
		else if (total == 21)
		{
			cout << "Well good thing we didn't bet any money huh?" << endl;
			cout << "Thank you for playing." << endl;
		}
	}



}

void GameStart(deck gamedeck)
{
	// second screen for game
	// users are told the deck will be shuffled
	// and will be asked if they want to cut the deck. 
	char ans = ' ';


	cout << "Let me shuffle the deck before we start..." << endl;
	gamedeck.shuffle(); cout << endl;
	cout << "Would you like me to cut the deck?(y/n)"; cin >> ans;


	// users can answer yes or no in cutting the deck. 
		while (ans != 'y' && ans != 'n')
		{
			cin.clear();
			cin.ignore(10000, '/n');
			cout << "You have entered an invalid answer, type y for yes or n for no: " << endl;
			cout << "Would you like me to cut the deck?"; cin >> ans;
		}
		if (ans == 'y')
		{

			gamedeck.cut((rand() % 51));
		}
		else if (ans == 'n')
		{
			cout << "Alright then. Let us begin!" << endl << endl;
			cout << "======================================" << endl;
		}

		//clear system screen since next section will be a lot of text. 
		system("CLS");

	midgame(gamedeck);

}

void BlackJack(deck gamedeck)
{
	// this fucntion runs the entire game. 
	IntroDisplay();
	GameStart(gamedeck);
}
