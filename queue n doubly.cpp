#include <iostream>
using namespace std;
/*The upcoming Data structure is a doubly linked list.
I will use two pointers (front) and (rear)
I will create a queue of time complexity O(1)

1- doubly node class*/
class DoublyNode{
public:
	int Data;
	DoublyNode* Next;
	DoublyNode* Prev;

	DoublyNode(){
	Data = 0;
	Next = NULL;
	Prev = NULL;
	}
};

//2- Class for Card queue which will represent player hand in "Money" game
class CardQueue{
private:
	DoublyNode* Front;
	DoublyNode* Rear;
	int Cards_Count;
public:
//3- default constructor
	CardQueue(){
		Front = NULL;
		Rear = NULL;
		Cards_Count = 0;
	}
//4- Function to check if list is empty
	bool IsEmpty(){
	if (Front == NULL && Rear == NULL) return true;
	else return false;
	}	
//5- function to add a number at the rear of the linked list
	void AddCard(int Card_Number){
		DoublyNode* Card = (DoublyNode*)malloc(sizeof(DoublyNode));
		Card->Data = Card_Number;
		if(IsEmpty()){
		Front = Card;
		Rear = Card;
		Front->Prev = Rear;
		Cards_Count = 1;
		}
		else{
		Rear->Prev = Card;
		Card->Next = Rear;
		Rear = Card;
		Cards_Count++;
		}
	}
//6-	function to dequeue (remove number from front)
	int RemoveCard(){
	DoublyNode* Temp = Front;
	int Card_Number = Front->Data;
	Front = Front->Prev;
	free(Temp);
	Cards_Count--;
	return Card_Number;
	}
// 7- peek function to check topmost card without removing it
int peek()
{
    if (IsEmpty()) return 0;
    return Front->Data;
}
// 8- display stack to be able to check all cards in it manually
	void DisplayCards()
{
	DoublyNode* temp = Front;
    while (temp != NULL) {
        cout << temp->Data << " ";
        temp = temp->Prev;
    }
}
};