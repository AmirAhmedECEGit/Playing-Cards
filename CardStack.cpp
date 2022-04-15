#include<iostream>
using namespace std;
/*Stack Using Singly Linked List with head reference pointing at the top of the stack
The Expected time complexity is O(1) to insert a new node at the top and O(1) to release a node
also if we used a variable "Cards_Count" to increment the during pushing and decrement in poping we can get an O(1) complexity to count cards

1- define the node class to be used in stack implementation*/
class StackNode{
public:		
	int			Data;
	StackNode*	Next;
	StackNode(){
	Data = 0;
	Next = NULL;
	}
};
// 2- define the stack class
class CardStack{
private:
	StackNode* Top;
	int Cards_Count;
public:
// 3- default constructor an empty stack
	CardStack(){
	Top = NULL;
	Cards_Count = 0;
	}
// 4-Empty Flag function
bool isEmpty()
{
	if(Top == NULL) return true;
	else return false;
}
// 5- push function
	void push(int Card)
{
    StackNode* New_Card = (StackNode*)malloc(sizeof(StackNode));
	New_Card->Data = Card;
    New_Card->Next = Top;
    Top = New_Card;
}
// 6- pop function
int pop()
{
    if (isEmpty())	return 0;
    StackNode* temp = Top;
    Top = Top->Next;
    int popped = temp->Data;
    free(temp);
    return popped;
}
// 7- peek function to check topmost card without removing it
int peek()
{
    if (isEmpty()) return 0;
    return Top->Data;
}
// 8- display stack to be able to check all cards in it manually
	void DisplayCards()
{
	StackNode* temp = Top;
    while (temp != NULL) {
        cout << temp->Data << " ";
        temp = temp->Next;
    }
}

};

