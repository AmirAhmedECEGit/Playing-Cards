#include "Playing_Hand.h"


//4-2 Playing Hand of Basra
//Type: AVL Tree
//Functionality: Draws Cards, Plays Cards, Check if empty

	Playing_Hand::Playing_Hand()
	{
		//Default constructor
	Root = NULL;
	Sum = 0;
	Count = 0;
	}
	void Playing_Hand::ResetHand(){
		//Deletes Hand
		Root = NULL;
		Sum=0;
		Count = 0;
	}
	bool Playing_Hand::IsFound(int Card){
		return Is_Found_In_Playing_Hand(Root,Card);
	}
	bool Playing_Hand::IsEmpty(){
		//Check if function is empty
		return(Root == NULL);
	}
	void Playing_Hand::DrawCard(int Card)
	{
		Root = insert(Root,Card);
		Sum = Sum+Card;
		Count++;
	}
	void Playing_Hand::DisplayHand()
	{
		Stylised_PreOrder(Root);
		cout<<"\n";
	}
	int Playing_Hand::PlayCard(int Card)
	{
		if(Is_Found_In_Playing_Hand(Root,Card))
		{
			Root = deletePlaying_Hand_Node(Root,Card);
			Sum = Sum-Card;
			Count--;
			return Card;
		}
		else
		{
			cout<<"You dont have that card, please input a card you own..\nCard:	";
			return PlayCard(CardInput());
		}
	}
