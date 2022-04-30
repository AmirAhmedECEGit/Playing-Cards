#pragma once
#include<iostream>
#include "Macros.h"
#include "Utility.h"
#include "AVL_Tree.h"
using namespace std;
//4-2 Playing Hand of Basra
//Type: AVL Tree
//Functionality: Draws Cards, Plays Cards, Check if empty
class Playing_Hand
{
private:
	Playing_Hand_Node* Root;

public:
	int Sum;
	int Count;
	Playing_Hand();
		//Default constructor
	void ResetHand();
		//Deletes Hand
	bool IsFound(int Card);
	bool IsEmpty();
		//Check if function is empty
	void DrawCard(int Card);
	void DisplayHand();
	int PlayCard(int Card);

};