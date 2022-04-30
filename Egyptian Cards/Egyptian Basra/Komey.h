#pragma once
#include<iostream>
#include "Macros.h"
#include "Utility.h"
#include "AVL_Tree.h"
#include "Playing_Hand.h"
#include "Floor.h"
using namespace std;
//4- Game Classes
//4-1 DeckHashTable
//Type: HashTable (array of size 13)
//functionality: Stores number of cards
//Draws card from it according to certain Hashing index
//initially is full


void parameter_change();

class Deck{
private:
	int DeckCards[13];

public:
	int RemainingCards;
	int Hash_Index(int Card_Number);
	Deck();
	void Reset_Deck();
	bool IsEmpty();
	bool CardExist(int Card);
	int DrawCard();
	int NumberDrawCard();
	void DisplayDeck();
};

class Basra{
private:
	//int Number_Of_Players;
	//Playing_Hand Player[3];
	Playing_Hand Player;
	Playing_Hand AI;
	Deck Kotshena;
	Floor Field;
	int Player_Score;
	int AI_Score;
public:
	Basra();
	void Reset();
	void PlayerDraw();
	void AIDraw();
	void FieldDraw();
	void Oppening();
	void EndTurn();
	void Text();
	void Play();
};
//class Basra AI vs AI
class Basra_AI_vs_AI{
private:
	Playing_Hand AI1;
	Playing_Hand AI2;
	Deck Kotshena;
	Floor Field;
	int AI1_Score;
	int AI2_Score;
public:
	Basra_AI_vs_AI();
	void Reset();
	void AI1Draw();
	void AI2Draw();
	void FieldDraw();
	void Oppening();
	void EndTurn();
	void Text();
	void Play();
};

