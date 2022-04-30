#pragma once
#include<iostream>
#include "Macros.h"
#include "Utility.h"
#include "AVL_Tree.h"
using namespace std;
//4-3 FieldHashTable
//Type: HashTable (array of size 13)
//functionality: Stores, Deletes, Searches and Compares
//Cards on field according to certain Hashing index (Number-1)%13 for 1->10, J=11, Q=12, K=13
//initially is empty, it should have the ability to compare any number/symbol to floor
//it should have the ability to remove certain number from floor
class Floor{
private:
	int FloorCards[13];
public:

	int FloorCardCount;

	

	Floor();
		//Default Constructor
	int Hash_Index(int Card_Number);
		//function that determines hashing index
	void Reset_Floor();
		//Empty the floor
	bool IsEmpty();
		//checks if deck is empty, returns 1 if empty and returns 0 if not empty
	bool CardExist(int Card);
	void PlaceCard(int Card);
	//places a card in its Hash index

	void DeleteCard(int Card);
		//deletes a card

	int EatsAllCards();
		//for when jack is played, El wallad bey204
	
	void FloorDisplay();
		//Displays floor cards

	int CardBankCheck (int Card);

	bool MultiFoursCheck(int Card);
	//check all four cards that can sum up to one card
	bool MultiThreesCheck(int Card);
	//check all three cards combinations that can sum up to one card
	bool MultiTwosCheck(int Card);
	//check all two cards combinations that can sum up to one card
	int CardRank(int Card);
	//returns the rank of a card
	//higher rank means better score when played
	//AI will use this function while human player cant

	int CardBank (int Card);
	int MultiFours(int Card);
	//banks all four cards that can sum up to one card
	int MultiThrees(int Card);
	//banks all three cards that can sum up to one card
	int MultiTwos(int Card);
};