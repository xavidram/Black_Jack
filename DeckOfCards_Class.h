/*
Xavid Ramirez - 3/06/2015
This deck of cards class will be used in the blackjack game.
*/
#include <iostream>
#include <string>
#include <time.h>
using namespace std;


class card
{
public:
	int number;
	string suit;
	// have suit array up here for assistance
	

	//basic constructor for unparamaterized card
	card()
	{
		string suitList[4] = { "Clubs", "Diamonds", "Hearts", "Spades" };
		number = rand() % 13 + 1;
		suit = suitList[rand() % 4];
	}
	// paramaterized constructor for card
	card(int value, string Isuits)
	{
		number = value;
		suit = Isuits;
	}
	// this prints out the card details
	void printCard()
	{
		cout << number << " " << suit;
	}
	bool operator <= (card y)
	{
		if (number <= y.number)
			return true;
		else
			false;
	}
};

class deck
{
private:
	//array to hold some cards.  Array is allocated by constructor
	card * cardArray;

	//size of cardArray, set by constructor
	int maxSize;

	//Number of cards in deck.  Should not exceed maxSize.
	int numCards;

	

public:
	//default constructor:  create the standard 52 card deck
	deck()
	{
		// total number of cards is 52
		numCards = 52;
		// array of suits that will be used later
		string suitList[4] = { "Clubs", "Diamonds", "Hearts", "Spades" };
		// this array will hold the deck
		cardArray = new card[numCards];
		// this will be used to control size of deck
		maxSize = numCards;

		// start with he first card and its value is 1
		int numbcontrol = 1;
		// but it will be placed at position 0 of array
		int i = 0;

		// this loop will put cards into the array in numbers based on their suit
		// as in all 1's then 2's  and so on
		while (i < numCards)
		{
			
			for (int j = 0; j < 4; j++)
			{
				cardArray[i].number = numbcontrol;
				cardArray[i].suit = suitList[j];
				i++;
			}
			numbcontrol++;
		}
		

	}

	//parameterized constructor:  create a special deck that has
	//card numbers from 1 to numberRange and numSuits different suits.
	//In addition, the names of the different suits will be provided
	//by the array of strings 'suitList'.  This constructor should
	//create a card for each possible pairing of a number and a suit.
	//Therefore, there should be numberRange*numSuits total cards.
	//If numberRange=13, numSuits=4, and
	//suitList = {"heart","club","spade","diamond"}, then this constructor
	//should create the same deck that would be created by
	//the default constructor.
	deck(int numberRange, int numSuits, string * suitList)
	{
		numCards = numberRange;
		cardArray = new card[numCards];
		maxSize = numCards;

		int numbcontrol = 1;
		int i = 0;
		while (i < numCards)
		{

			for (int j = 0; j < numSuits; j++)
			{
				cardArray[i].number = numbcontrol;
				cardArray[i].suit = suitList[j];
				i++;
			}
			numbcontrol++;
		}
	}

	//place input card onto top of deck
	void addCardTop(card)
	{
		card *newdeck;
		// new array will hold all cards if reached
		// size limit of old array
		if (numCards = maxSize)
		{
			maxSize = numCards * 2;
			newdeck = new card[maxSize];
		}
		
		//put all cards in array of new size
		for (int i = 0; i < numCards; i++)
		{
			newdeck[i] = cardArray[i];
		}

		newdeck[numCards];
		numCards++;
	
	}

	//remove and return the card at the top of the deck
	card dealCardFromTop()
	{
		//card variable to hold returning card
		card x;
		// put card from top into x
		x = cardArray[numCards - 1];
		// decrement size of deck
		numCards--;
		//return the card
		return x;
	}

	//remove and return a random card from the deck
	card dealRandomCard()
	{
		// card x will hold card to be returned
		card x;
		// value will hold random element value for the random card
		int value = rand() % numCards - 1;
		// put the card in element value into x
		x = cardArray[value];
		// put last card in array into place of the randomly selected card
		// and decrease the number of cards in array.
		cardArray[value] = cardArray[numCards - 1];
		numCards--;
		return x;
	}

	//rearrange all the cards in the deck into random order
	void shuffle()
	{
		// card to hold temp value
		card tmp;

		/* this loop makes two random values that ill find two random elements in the array
		and swap them with eachother using the temp variable as a place holder and will continue 
		doing this till end of array for a good shuffle*/
		for (int i = 0; i < numCards; i++)
		{
			int value1 = (rand() % numCards );
			int value2 = (rand() % numCards );
			tmp = cardArray[value1];
			cardArray[value1] = cardArray[value2];
			cardArray[value2] = tmp;
		}
	}

	//Cut the deck at position'p':  swap the lower portion
	//of the card array (from 0 to p-1) with the
	//top portion of the deck (position p to numCards-1).
	void cut(int p)
	{
		card *cut = new card[numCards];
		int i = 0;
		// phold initialized at position p
		int phold = p;
		
		// this loop will start at cut and put items into array until it reaches
		//end of the origian array
		for (phold; phold <= numCards-1; i++)
		{
			cut[i] = cardArray[phold];
			phold++;

		}
		// phold is set back to 0 so it can 
		// flter in the lower half of the cards
		phold = 0;
		// this loop puts the lower half of the cards of the original array
		// into the new array
		for (i; i <= numCards-1; i++)
		{
			cut[i] = cardArray[phold];
			phold++;
		}
		// delete old card array so memory leak doesnt happen. 
		delete[] cardArray;
		// point cardArray at cut
		cardArray = cut;
	}

	//arrange the cards into increasing order by card number.
	
	void PrintDeck()
	{
		// this is just in case I want to print out the deck. 
		for (int i = 0; i < numCards; i++)
		{
			cout << cardArray[i].number << " " << cardArray[i].suit << endl;
		}
	}

	void sort()
	{
		card tmp;
		int pos_small;

		for (int i = 0; i <= numCards -1; i++)
		{
			pos_small = i;
			for (int j = i+1; j < numCards; j++)
			{
				if (cardArray[j].number < cardArray[pos_small].number)
				{
					pos_small = j;
				}


			}


			if (pos_small != i)
			{
				tmp = cardArray[i];
				cardArray[i] = cardArray[pos_small];
				cardArray[pos_small] = tmp;
			}

		}

	}
	/////////////////////////////////////////////////////////////////////


	//////////////////////////////////////////////////////////
	
};