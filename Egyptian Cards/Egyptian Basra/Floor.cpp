#include "Floor.h"


//4-3 FieldHashTable
//Type: HashTable (array of size 13)
//functionality: Stores, Deletes, Searches and Compares
//Cards on field according to certain Hashing index (Number-1)%13 for 1->10, J=11, Q=12, K=13
//initially is empty, it should have the ability to compare any number/symbol to floor
//it should have the ability to remove certain number from floor


	
	Floor::Floor(){
		//Default Constructor
		FloorCardCount = 0;
		for (int i = 0; i < 13; i++)
		{
			FloorCards[i] = 0;
		}
	}
	int Floor::Hash_Index(int Card_Number)
	{
		//function that determines hashing index
		return ((Card_Number-1)%13);
	}
	void Floor::Reset_Floor(){
		//Empty the floor
		FloorCardCount = 0;
		for (int i = 0; i < 13; i++)
		{
			FloorCards[i] = 0;
		}
	}
	bool Floor::IsEmpty()
	{
		//checks if deck is empty, returns 1 if empty and returns 0 if not empty
		if (FloorCardCount>0) return false;
		else return true;
	}
	bool Floor::CardExist(int Card){
		if (FloorCards[Hash_Index(Card)]>0) return true;
		else return false;
	}
	void Floor::PlaceCard(int Card)
	{	//places a card in its Hash index
		FloorCards[Hash_Index(Card)]++;
		FloorCardCount++;
	}
	void Floor::DeleteCard(int Card)
	{
		//deletes a card
		if(CardExist(Card))
		{
			FloorCards[Hash_Index(Card)]--;
			FloorCardCount--;
		}
	}
	int Floor::EatsAllCards()
	{
		//for when jack is played
		int temp = FloorCardCount;
		FloorCardCount = 0;
		for (int i = 0; i < 13; i++)
		{
			FloorCards[i]=0;
		}
		return temp;
	}
	void Floor::FloorDisplay()
	{
		//Displays floor cards
		for (int i = 0; i < 13; i++)
		{
			for (int j = 0; j < FloorCards[i]; j++)
			{
				Card_Display(i+1);
			}
		}
	}
	int Floor::CardBankCheck (int Card)
	{
		if(CardExist(Card))
		{
			return FloorCards[Hash_Index(Card)];
		}
		else return 0;
	}
	bool Floor::MultiFoursCheck(int Card)
	{
		if(Card == 10 && FloorCardCount>=4)
		{
			//10 = 4+3+2+1
			if(CardExist(1)&&CardExist(2)&&CardExist(3)&&CardExist(4))
				return true;
			else
				return false;
		}
		else
			return false;
	}
	bool Floor::MultiThreesCheck(int Card)
	{
		if(Card < 6 || FloorCardCount<3 || Card>10) return false;
		else
		{
			//6 = 3+2+1
			if((Card == 6) && CardExist(1) && CardExist(2) && CardExist(3))
				return true;
			//7 = 4+2+1
			else if((Card == 7) && CardExist(1) && CardExist(2) && CardExist(4))
				return true;
			//8 = 5+2+1
			else if((Card == 8) && CardExist(1) && CardExist(2) && CardExist(5))
				return true;
			//9 = 6+2+1 = 4+3+2
			else if((Card == 9) && CardExist(1) && CardExist(2) && CardExist(4))
				return true;
			else if((Card == 9) && CardExist(4) && CardExist(3) && CardExist(2))
				return true;
			//10 = 7+2+1 = 5+3+2
			else if((Card == 10) && CardExist(1) && CardExist(2) && CardExist(7))
				return true;
			else if((Card == 10) && CardExist(5) && CardExist(3) && CardExist(2))
				return true;
			else
				return false;
		}
	}
	bool Floor::MultiTwosCheck(int Card)
{
		if(FloorCardCount<2 || Card>10) return false;
		else
		{
			//2 = 1+1
			if((Card == 2) && CardBankCheck(1)>=2)
				return true;
			//3 = 2+1
			else if((Card == 3) && CardExist(2) && CardExist(1))
				return true;
			//4 = 2+2
			else if((Card == 4) && CardBankCheck(2)>=2)
				return true;
			//4 = 3+1
			else if((Card == 4) && CardExist(1) && CardExist(3))
				return true;
			//5 = 4+1
			else if((Card == 5) && CardExist(4) && CardExist(1))
				return true;
			//5 = 3+2
			else if((Card == 5) && CardExist(3) && CardExist(2))
				return true;
			//6 = 5+1 = 4+2 = 3+3
			else if((Card == 6) && CardExist(1) && CardExist(5))
				return true;
			else if((Card == 6) && CardExist(4) && CardExist(2))
				return true;
			else if((Card == 6) && CardBankCheck(3)>=2)
				return true;
			//7 = 6+1
			else if((Card == 7) && CardExist(6) && CardExist(1))
				return true;
			//7 = 5+2
			else if((Card == 7) && CardExist(2) && CardExist(5))
			return true;
			//7 = 4+3
			else if((Card == 7) && CardExist(3) && CardExist(4))
				return true;
			//8 = 7+1
			else if((Card == 8) && CardExist(1) && CardExist(7))
				return true;
			//8 = 6+2
			else if((Card == 8) && CardExist(2) && CardExist(6))
				return true;
			//8 = 5+3
			else if((Card == 8) && CardExist(3) && CardExist(5))
				return true;
			//8 = 4+4
			else if((Card == 8) && CardBankCheck(4)>=2)
				return true;
			//9 = 8+1
			else if((Card == 9) && CardExist(8) && CardExist(1))
				return true;
			//9 = 7+2
			else if((Card == 9) && CardExist(2) && CardExist(7))
			return true;
			//9 = 6+3
			else if((Card == 9) && CardExist(3) && CardExist(6))
				return true;
			//9 = 5+4
			else if((Card == 9) && CardExist(5) && CardExist(4))
				return true;
			//10 = 9+1
			else if((Card == 10) && CardExist(9) && CardExist(1))
				return true;
			//10 = 8+2
			else if((Card == 10) && CardExist(2) && CardExist(8))
			return true;
			//10 = 7+3
			else if((Card == 10) && CardExist(3) && CardExist(7))
				return true;
			//10 = 6+4
			else if((Card == 10) && CardExist(6) && CardExist(4))
				return true;
			//10 = 5+5
			else if((Card == 10) && CardBankCheck(5)>=2)
				return true;
			else
				return false;
		}
	}
	int Floor::CardRank(int Card)
	{
		//returns the rank of a card
		//higher rank means better score when played
		//AI will use this function while human player cant
		if (Card>=1 && Card<=10)
			return Biggest(CardBankCheck(Card)+MultiFoursCheck(Card),CardBankCheck(Card)+MultiThreesCheck(Card),CardBankCheck(Card)+MultiTwosCheck(Card));
		else if (Card == 11)
			return FloorCardCount;
		else
			return CardBankCheck(Card);
	}
	int Floor::CardBank (int Card)
	{
		if(CardExist(Card))
		{
			int Temp = FloorCards[Hash_Index(Card)];
			FloorCards[Hash_Index(Card)] = 0;
			FloorCardCount = FloorCardCount - Temp;
			return Temp;
		}
		else return 0;
	}
	int Floor::MultiFours(int Card)
	{
		if(Card == 10 && FloorCardCount>=4)
		{
			//10 = 4+3+2+1
			if(CardExist(1)&&CardExist(2)&&CardExist(3)&&CardExist(4))
			{
				DeleteCard(1);DeleteCard(2);DeleteCard(3);DeleteCard(4);
				return 4; //score returned
			}
			else
				return 0;
		}
		else
			return 0;
	}
	int Floor::MultiThrees(int Card)
	{
	if(Card < 6 || FloorCardCount<3 || Card>10) return 0;
		else
		{
			//6 = 3+2+1 = 2+2+2
			if((Card == 6) && CardExist(1) && CardExist(2) && CardExist(3))
			{
				DeleteCard(1);
				DeleteCard(2);
				DeleteCard(3);
				return 3;
			}

			//7 = 4+2+1
			else if((Card == 7) && CardExist(1) && CardExist(2) && CardExist(4))
			{
				DeleteCard(1);
				DeleteCard(2);
				DeleteCard(4);
				return 3;
			}
			//8 = 5+2+1
			else if((Card == 8) && CardExist(1) && CardExist(2) && CardExist(5))
			{
				DeleteCard(1);
				DeleteCard(2);
				DeleteCard(5);
				return 3;
			}
			//9 = 6+2+1 = 4+3+2 = 3+3+3
			else if((Card == 9) && CardExist(1) && CardExist(2) && CardExist(6))
			{
				DeleteCard(1);
				DeleteCard(2);
				DeleteCard(6);
				return 3;
			}
			else if((Card == 9) && CardExist(4) && CardExist(3) && CardExist(2))
			{
				DeleteCard(4);
				DeleteCard(2);
				DeleteCard(3);
				return 3;
			}

			//10 = 7+2+1 = 5+3+2
			else if((Card == 10) && CardExist(1) && CardExist(2) && CardExist(7))
			{
				DeleteCard(1);
				DeleteCard(2);
				DeleteCard(7);
				return 3;
			}
			else if((Card == 10) && CardExist(5) && CardExist(3) && CardExist(2))
			{
				DeleteCard(5);
				DeleteCard(2);
				DeleteCard(3);
				return 3;
			}
			else
				return 0;
		}
	}
	int Floor::MultiTwos(int Card)
{
		if(FloorCardCount<2 || Card>10) return false;
		else
		{
			//2 = 1+1
			if((Card == 2) && CardBankCheck(1)>=2)
			{
				DeleteCard(1);
				DeleteCard(1);
				return 2;
			}
			//3 = 2+1
			else if((Card == 3) && CardExist(2) && CardExist(1))
			{
				DeleteCard(2);
				DeleteCard(1);
				return 2;
			}
			//4 = 2+2
			else if((Card == 4) && CardBankCheck(2)>=2)
			{
				DeleteCard(2);
				DeleteCard(2);
				return 2;
			}
			//4 = 3+1
			else if((Card == 4) && CardExist(1) && CardExist(3))
			{
				DeleteCard(3);
				DeleteCard(1);
				return 2;
			}
			//5 = 4+1
			else if((Card == 5) && CardExist(4) && CardExist(1))
			{
				DeleteCard(4);
				DeleteCard(1);
				return 2;
			}
			//5 = 3+2
			else if((Card == 5) && CardExist(3) && CardExist(2))
			{
				DeleteCard(3);
				DeleteCard(2);
				return 2;
			}
			//6 = 5+1 = 4+2 = 3+3
			else if((Card == 6) && CardExist(1) && CardExist(5))
			{
				DeleteCard(5);
				DeleteCard(1);
				return 2;
			}
			else if((Card == 6) && CardExist(4) && CardExist(2))
			{
				DeleteCard(4);
				DeleteCard(2);
				return 2;
			}
			else if((Card == 6) && CardBankCheck(3)>=2)
			{
				DeleteCard(3);
				DeleteCard(3);
				return 2;
			}
			//7 = 6+1
			else if((Card == 7) && CardExist(6) && CardExist(1))
			{
				DeleteCard(6);
				DeleteCard(1);
				return 2;
			}
			//7 = 5+2
			else if((Card == 7) && CardExist(2) && CardExist(5))
			{
				DeleteCard(5);
				DeleteCard(2);
				return 2;
			}
			//7 = 4+3
			else if((Card == 7) && CardExist(3) && CardExist(4))
			{
				DeleteCard(4);
				DeleteCard(3);
				return 2;
			}
			//8 = 7+1
			else if((Card == 8) && CardExist(1) && CardExist(7))
			{
				DeleteCard(7);
				DeleteCard(1);
				return 2;
			}
			//8 = 6+2
			else if((Card == 8) && CardExist(2) && CardExist(6))
			{
				DeleteCard(6);
				DeleteCard(2);
				return 2;
			}
			//8 = 5+3
			else if((Card == 8) && CardExist(3) && CardExist(5))
			{
				DeleteCard(5);
				DeleteCard(3);
				return 2;
			}
			//8 = 4+4
			else if((Card == 8) && CardBankCheck(4)>=2)
			{
				DeleteCard(4);
				DeleteCard(4);
				return 2;
			}
			//9 = 8+1
			else if((Card == 9) && CardExist(8) && CardExist(1))
			{
				DeleteCard(8);
				DeleteCard(1);
				return 2;
			}
			//9 = 7+2
			else if((Card == 9) && CardExist(2) && CardExist(7))
			{
				DeleteCard(7);
				DeleteCard(2);
				return 2;
			}
			//9 = 6+3
			else if((Card == 9) && CardExist(3) && CardExist(6))
			{
				DeleteCard(6);
				DeleteCard(3);
				return 2;
			}
			//9 = 5+4
			else if((Card == 9) && CardExist(5) && CardExist(4))
			{
				DeleteCard(5);
				DeleteCard(4);
				return 2;
			}
			//10 = 9+1
			else if((Card == 10) && CardExist(9) && CardExist(1))
			{
				DeleteCard(9);
				DeleteCard(1);
				return 2;
			}
			//10 = 8+2
			else if((Card == 10) && CardExist(2) && CardExist(8))
			{
				DeleteCard(8);
				DeleteCard(2);
				return 2;
			}
			//10 = 7+3
			else if((Card == 10) && CardExist(3) && CardExist(7))
			{
				DeleteCard(7);
				DeleteCard(3);
				return 2;
			}
			//10 = 6+4
			else if((Card == 10) && CardExist(6) && CardExist(4))
			{
				DeleteCard(6);
				DeleteCard(4);
				return 2;
			}
			//10 = 5+5
			else if((Card == 10) && CardBankCheck(5)>=2)
			{
				DeleteCard(5);
				DeleteCard(5);
				return 2;
			}
			else
				return 0;
		}
	}