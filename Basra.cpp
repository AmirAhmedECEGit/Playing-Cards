/*----------------------------------------------------------------------------------------------------------
General Code Flow:
1- Global Constants/Parameters definition
2- Utility Functions that were used in other complex functions definition
3- Data Structures Definition (AVL, Linked List, Doubly Linked List)
4- Game Objects Classes based on the pre-defined data structures
5- Each Game Class with all needed Game Objects
6- Playing the game at main by calling Basra.play() for example

Time Complexity Studying:
1- measuring processor clocks using counts and clocks
2- measuring elapsed time in each part of code
3- comparing different data structures in terms of access and search speed
	to optimize code before implementation
	example: array complexity to search for 4 numbers that sums up to 10 is O(n^4)
			whereas same functionality can be achieved in a hash table with O(1)!!!
------------------------------------------------------------------------------------------------------------
parameters needed:	Deck Size (52 or 104)
this size can be controlled by a parameter N , cards = N*13, N by default is 4
N is the parameter that if we changed the complexity of code will increase
------------------------------------------------------------------------------------------------------------*/
//Libraries
#include <iostream>		//input and output
#include <string.h>		//string comparisons and strlen()
#include <stdio.h>		//ip/op
#include <stdlib.h>		//standard library
#include <ctime>		//clock(), time()
#include <math.h>		//power function
#include <limits>
using namespace std;
//1- Parameters Definition
const int Max_C_String_Size = 100;		//defines the input/output carriage needed when dealing with strings
int N	=	 4;							//defines the number of cards in one hand in games like Basra (4 or 8) recommended
int Deck_Size = 13*N;				//defines number of total cards (52, 104, etc)
char dummy_variable [Max_C_String_Size] = {0};

//2- Utility Functions
//2.1- Elapsed_Time_In_Seconds
double Now(){
	time_t current = clock();
	return (double)current/CLOCKS_PER_SEC;
}
//2.2- Elapsed number of processor clocks
double Clocks(){
	time_t current = clock();
	return (double)current;
}
//2.3- Code to randomize number
int Random(){
	int x = 1+rand()%13;
		while (x<0 || x>13){
			x = 1+rand()%13;
		}
	return (x);
// number range is fron 1 to 13 which suits my playing cards 1->10,J,Q,K
}
int NumberRandom(){
	int x = 1+rand()%10;
		while (x<0 || x>10){
			x = 1+rand()%10;
		}
	return (x);
// number range is fron 1 to 10 which suits my playing cards 1->10 in games such as Money and BlackJack
}
void Synchronus(){
	srand((unsigned int)time(NULL));
	//based on universal time since 1970 thingy <totally random>
	//use it in Main code bedore game starts
}
//2.4- Code to display playing cards as stylised model where 1->10 the J = 11, Q = 12, K = 13
void Card_Display(int x){
		if(x==1)
		cout<<"[* 1 ]";
		else if(x==2)
		cout<<"[* 2 ]";
		else if(x==3)
		cout<<"[* 3 ]";
		else if(x==4)
		cout<<"[* 4 ]";
		else if(x==5)
		cout<<"[* 5 ]";
		else if(x==6)
		cout<<"[* 6 ]";
		else if(x==7)
		cout<<"[* 7 ]";
		else if(x==8)
		cout<<"[* 8 ]";
		else if(x==9)
		cout<<"[* 9 ]";
		else if(x==10)
		cout<<"[* 10]";
		else if(x==11)
		cout<<"[* J ]";
		else if(x==12)
		cout<<"[* Q ]";
		else if(x==13)
		cout<<"[* K ]";
		else
		cout<<"[* ??]";
}

//2.5- Code to convert user input into numbers and reject bad input
bool Find (char str[], char sub[]){
	//2.5.1 returns true if a substring is found and false if not
	char temp[Max_C_String_Size];
	for(unsigned int i = 0; i<strlen(str); i++)
	{
		for (unsigned int j = 0; j < strlen(sub); j++)
		{
			if(str[i+j] == sub[j])
			{
				temp[j]=sub[j];
					for(unsigned int k = 0;k<=strlen(sub);k++)
					{
						if(k == strlen(sub)) return true;
						else if(temp[k] == sub[k]) continue;
						else break;
					}
			}
			else break;
		}
	 }
	return false;
}
bool IsNumber(char Temp[]) {
	//2.5.2 checks if input carriage contains a valid card number
		int Temp_Length_Counter = 0;
		int Counter = 0;
		int Sum = 0;
		for (int i = 0 ; Max_C_String_Size-1 ; i++){
			Counter++;
			if((Temp[i]>='0' && Temp[i]<='9')||(Temp[i] == ' ')||(Temp[i] == '\0')){
                    if (Temp[i]=='\0') break;
				else if(Temp[i]==' ' &&  Temp_Length_Counter == 0) continue;				//space at the start is allowed
				else if (Temp[i]==' ' &&  Counter == (strlen(Temp))) continue;				//space in end is allowed
				else if (Temp[i]==' ' &&  Temp_Length_Counter > 0) return false;			//space in middle is not allowed
				else{
					Temp_Length_Counter++;
					continue;
				}
			}
			else return false;
		}
		if (Temp_Length_Counter>2) return false;
		for (int i = 0; Temp_Length_Counter ; i++ ){
            if((Temp[i]>='0' && Temp[i]<='9')){
                    Temp_Length_Counter--;
                    if(Temp_Length_Counter) Sum = Sum + (Temp[i]-'0')*10;
                    else Sum = Sum + Temp[i] - '0';
            }
		}
		if (Sum>13) return false;
		if (Sum<1) return false;
		return true;
}
bool IsLetter(char Temp[]) {
	//2.5.3 Checks if input carriage contains a valid card litera
		int Temp_Length_Counter = 0;
		int Counter = 0;
		for (int i = 0 ; Max_C_String_Size-1 ; i++){
			Counter++;
			if((Temp[i]>='a' && Temp[i]<='z')||(Temp[i]>='A' && Temp[i]<='Z')||(Temp[i] == ' ')||(Temp[i] == '\0')){
                     if (Temp[i]=='\0') break;
				if(Temp[i]==' ' &&  Temp_Length_Counter == 0) continue;				//space at the start is allowed
				else if (Temp[i]==' ' &&  Counter == (strlen(Temp))) continue;		//single space in end is allowed
				else if (Temp[i]==' ' &&  Temp_Length_Counter > 0) return false;	//space in middle is not allowed
				else{
					Temp_Length_Counter++;
					continue;
				}
			}
			else return false;
		}
		if (Temp_Length_Counter>5) return false;
		else return true;
}
int CardInput(){
	char Temp[Max_C_String_Size] = {0};

	cin.getline(Temp,Max_C_String_Size);
	while(Temp[0]=='\0' || !(IsNumber(Temp) || IsLetter(Temp))){
		//Check For Empty Input or Symbols and bad letters
		cout<<"Bad Input \nRe-Input Number(1->10) or Letters (J,Q,K):\nCard: ";
		cin.getline(Temp,Max_C_String_Size);
	}
	if		(Find(Temp,"13")||Find(Temp,"K")||Find(Temp,"k")||Find(Temp,"king")||Find(Temp,"King")||Find(Temp,"KING"))		return 13;
	else if (Find(Temp,"12")||Find(Temp,"Q")||Find(Temp,"q")||Find(Temp,"queen")||Find(Temp,"Queen")||Find(Temp,"QUEEN"))	return 12;
	else if (Find(Temp,"11")||Find(Temp,"J")||Find(Temp,"j")||Find(Temp,"jack")||Find(Temp,"Jack")||Find(Temp,"JACK"))		return 11;
	else if (Find(Temp,"10")||Find(Temp,"TEN")||Find(Temp,"Ten")||Find(Temp,"ten"))		 return 10;
	else if (Find(Temp,"9")||Find(Temp,"NINE")||Find(Temp,"Nine")||Find(Temp,"nine"))	 return 9;
	else if (Find(Temp,"8")||Find(Temp,"EIGHT")||Find(Temp,"Eight")||Find(Temp,"eight")) return 8;
	else if (Find(Temp,"7")||Find(Temp,"SEVEN")||Find(Temp,"Seven")||Find(Temp,"seven")) return 7;
	else if (Find(Temp,"6")||Find(Temp,"SIX")||Find(Temp,"Six")||Find(Temp,"six"))		 return 6;
	else if (Find(Temp,"5")||Find(Temp,"FIVE")||Find(Temp,"Five")||Find(Temp,"five"))	 return 5;
	else if (Find(Temp,"4")||Find(Temp,"FOUR")||Find(Temp,"Four")||Find(Temp,"four"))	 return 4;
	else if (Find(Temp,"3")||Find(Temp,"THREE")||Find(Temp,"Three")||Find(Temp,"three")) return 3;
	else if (Find(Temp,"2")||Find(Temp,"TWO")||Find(Temp,"Two")||Find(Temp,"two"))		 return 2;
	else if (Find(Temp,"1")||Find(Temp,"ONE")||Find(Temp,"One")||Find(Temp,"one"))		 return 1;
	else return 0;
}

//2.6- A utility function to get Maximum of two integers
int Max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

//2.7- Option checking, number input function
int  PA_Opt_in (int n)		//Positive Option input fucntion
	{
		int x;
    	std::cin >> x;
		while((std::cin.fail()) || (x<1||x>n)) //gives 1 if cin fails or x is not among option
    		{
        		std::cin.clear();
        		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        		std::cout << "Bad entry. chooose a valid option: ";
        		std::cin >> x;
    		}
		return x;
	}
//2.8- Find Biggest element in 3 elements
int Biggest(int x,int y,int z)
{
	int temp = x;
	if(y>temp) temp = y;
	if(z>temp) temp = z;
	return temp;
}

//2.9- Find Biggest element in an array
int MaxOf(int arr[13]){
int temp = arr[0];
int index = 0;
for (int i = 1; i < 13; i++)
{
	if(temp < arr[i])
	{
		temp=arr[i];
		index = i;
	}
}
return (index+1);
}

//2.10- Intro Text Display
void Intro()
{
cout<<"Hall of Glory:\n";
cout<<"1- Amir Ahmed Hassan Mohamed\n";
cout<<"2- Ahmed Sayed Bakry\n";
cout<<"3- Omnia Ehab\n";
cout<<"\n";
cout<<"Game:\n";
cout<<"Kotshena\n";
cout<<"we had the idea to create Kotshena then add the Egyptian spice and\n";
cout<<"involve not only foreign game modes but also Egyptian games\n";
cout<<"-------------------------------------------------\n";
}
void Basra_Intro()
{
cout<<"Rules:\n";
cout<<"Egyptian Basra:\n";
cout<<"1.1- Cards are Numbers (1->10) and Literals (J,Q,K)\n";
cout<<"1.2- in the starting round, each player draws 4 random cards and field has 4 random cards too.\n";
cout<<"1.3- in your turn you play a card to field, you take all field cards that have\n";
cout<<"same card number as yours or those who sums up to it and bank them as a score.\n";
cout<<"example: 10 = 4+3+2+1 = 5+4+1 = 5+3+2 = 6+3+1 = 7+2+1 = 8+2 =....\n";
cout<<"1.4- the \"J\" card is called \"Jack\" -El Wallad- has the ability to take\n";
cout<<"all cards on field as score, in case field is not empty.\n";
cout<<"1.5- When deck and hand cards end, player with most score wins\n";
cout<<"Press Enter to Continue Playing Game....";
cin.getline(dummy_variable,Max_C_String_Size);
}
//-----------------------------------------------------------------------

//3- Data Structures
//3.1- AVL Tree
class Playing_Hand_Node
{
	// An AVL tree Playing_Hand_Node
	public:
	int Data;
	Playing_Hand_Node *Left;
	Playing_Hand_Node *Right;
	int Hand_AVL_Height;
};
//3.1.1 A utility function to get the Height of the tree
int Hand_AVL_Height(Playing_Hand_Node *N)
{

	if (N == NULL)
		return 0;
	return N->Hand_AVL_Height;
}
//3.1.2 A utility function to check if tree is empty
bool IsEmptyHand(Playing_Hand_Node *Root){
		//Check if function is empty
		return(Root == NULL);
}
//3.1.3
// Helper function that allocates a
//new Playing_Hand_Node with the given Data and
//NULL Left and Right pointers.
Playing_Hand_Node* newPlaying_Hand_Node(int Data)
{
	Playing_Hand_Node* Temp = (Playing_Hand_Node*)malloc(sizeof(Playing_Hand_Node));
	Temp->Data = Data;
	Temp->Left = NULL;
	Temp->Right = NULL;
	Temp->Hand_AVL_Height = 1;	// new Playing_Hand_Node is initially
						// added at leaf
	return(Temp);
}
//3.1.4
// A utility function to Right
// rotate subtree rooted with y
// See the diagram given above.
Playing_Hand_Node *RightRotate(Playing_Hand_Node *y)
{

	Playing_Hand_Node *x = y->Left;
	Playing_Hand_Node *T2 = x->Right;

	// Perform rotation
	x->Right = y;
	y->Left = T2;

	// Update Hand_AVL_Heights
	y->Hand_AVL_Height = Max(Hand_AVL_Height(y->Left),
					Hand_AVL_Height(y->Right)) + 1;
	x->Hand_AVL_Height = Max(Hand_AVL_Height(x->Left),
					Hand_AVL_Height(x->Right)) + 1;

	// Return new root
	return x;
}
//3.1.5
// A utility function to Left
// rotate subtree rooted with x
// See the diagram given above.
Playing_Hand_Node *LeftRotate(Playing_Hand_Node *x)
{
	Playing_Hand_Node *y = x->Right;
	Playing_Hand_Node *T2 = y->Left;

	// Perform rotation
	y->Left = x;
	x->Right = T2;

	// Update Hand_AVL_Heights
	x->Hand_AVL_Height = Max(Hand_AVL_Height(x->Left),
					Hand_AVL_Height(x->Right)) + 1;
	y->Hand_AVL_Height = Max(Hand_AVL_Height(y->Left),
					Hand_AVL_Height(y->Right)) + 1;

	// Return new root
	return y;
}
//3.1.6
//Utility to check Balance for AVL tree
int getBalance(Playing_Hand_Node *N)
{
	if (N == NULL)
		return 0;
	return Hand_AVL_Height(N->Left) - Hand_AVL_Height(N->Right);
}
//3.1.7
// Recursive function to insert a Data
// in the subtree rooted with Playing_Hand_Node and
// returns the new root of the subtree.
// 1. Perform the normal BST insertion
Playing_Hand_Node* insert(Playing_Hand_Node* Playing_Hand_Node, int Data)
{

	if (Playing_Hand_Node == NULL)
		return(newPlaying_Hand_Node(Data));

	if (Data < Playing_Hand_Node->Data)
		Playing_Hand_Node->Left = insert(Playing_Hand_Node->Left, Data);
	else if (Data >= Playing_Hand_Node->Data)
		Playing_Hand_Node->Right = insert(Playing_Hand_Node->Right, Data);
	return Playing_Hand_Node;

	// 2. Update Hand_AVL_Height of this ancestor Playing_Hand_Node
	Playing_Hand_Node->Hand_AVL_Height = 1 + Max(Hand_AVL_Height(Playing_Hand_Node->Left),
						Hand_AVL_Height(Playing_Hand_Node->Right));

	// 3. Get the balance factor of this ancestor
	//	Playing_Hand_Node to check whether this Playing_Hand_Node became
	//	unbalanced
	int balance = getBalance(Playing_Hand_Node);

	// If this Playing_Hand_Node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && Data < Playing_Hand_Node->Left->Data)
		return RightRotate(Playing_Hand_Node);

	// Right Right Case
	if (balance < -1 && Data > Playing_Hand_Node->Right->Data)
		return LeftRotate(Playing_Hand_Node);

	// Left Right Case
	if (balance > 1 && Data > Playing_Hand_Node->Left->Data)
	{
		Playing_Hand_Node->Left = LeftRotate(Playing_Hand_Node->Left);
		return RightRotate(Playing_Hand_Node);
	}

	// Right Left Case
	if (balance < -1 && Data < Playing_Hand_Node->Right->Data)
	{
		Playing_Hand_Node->Right = RightRotate(Playing_Hand_Node->Right);
		return LeftRotate(Playing_Hand_Node);
	}

	// return the (unchanged) Playing_Hand_Node pointer
	return Playing_Hand_Node;
}
//3.1.8
// A utility function to print Stylised_PreOrder [* 1 ]
// traversal of the tree.
// The function also prints Hand_AVL_Height
// of every Playing_Hand_Node
void Stylised_PreOrder(Playing_Hand_Node *root)
{
	if(root != NULL)
	{
		Card_Display(root->Data);
		Stylised_PreOrder(root->Left);
		Stylised_PreOrder(root->Right);
	}
}
//3.1.9 loop down to find the Leftmost leaf
Playing_Hand_Node * minValuePlaying_Hand_Node(Playing_Hand_Node* Temp)
{
	Playing_Hand_Node* current = Temp;
	while (current->Left != NULL)
		current = current->Left;
	return current;
}

//3.1.10
// Recursive function to delete an AVL Node
// with given Data from subtree with
// given root. It returns root of the
// modified subtree.
Playing_Hand_Node* deletePlaying_Hand_Node(Playing_Hand_Node* root, int Data)
{
	// STEP 1: PERFORM STANDARD BST DELETE
	if (root == NULL)
		return root;

	// If the Data to be deleted is smaller
	// than the root's Data, then it lies
	// in Left subtree
	if ( Data < root->Data )
		root->Left = deletePlaying_Hand_Node(root->Left, Data);

	// If the Data to be deleted is greater
	// than the root's Data, then it lies
	// in Right subtree
	else if( Data > root->Data )
		root->Right = deletePlaying_Hand_Node(root->Right, Data);

	// if Data is same as root's Data, then
	// This is the Playing_Hand_Node to be deleted
	else
	{
		// Playing_Hand_Node with only one child or no child
		if( (root->Left == NULL) ||
			(root->Right == NULL) )
		{
			Playing_Hand_Node *temp = root->Left ?
						root->Left :
						root->Right;

			// No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // One child case
			*root = *temp; // Copy the contents of
						// the non-empty child
			free(temp);
		}
		else
		{
			// Playing_Hand_Node with two children: Get the inorder
			// successor (smallest in the Right subtree)
			Playing_Hand_Node* temp = minValuePlaying_Hand_Node(root->Right);

			// Copy the inorder successor's
			// data to this Playing_Hand_Node
			root->Data = temp->Data;

			// Delete the inorder successor
			root->Right = deletePlaying_Hand_Node(root->Right,
									temp->Data);
		}
	}
	// If the tree had only one Playing_Hand_Node
	// then return
	if (root == NULL)
	return root;

	// STEP 2: UPDATE Hand_AVL_Height OF THE CURRENT Playing_Hand_Node
	root->Hand_AVL_Height = 1 + Max(Hand_AVL_Height(root->Left),
						Hand_AVL_Height(root->Right));

	// STEP 3: GET THE BALANCE FACTOR OF
	// THIS Playing_Hand_Node (to check whether this
	// Playing_Hand_Node became unbalanced)
	int balance = getBalance(root);

	// If this Playing_Hand_Node becomes unbalanced,
	// then there are 4 cases
	// Left Left Case
	if (balance > 1 &&
		getBalance(root->Left) >= 0)
		return RightRotate(root);
	// Left Right Case
	if (balance > 1 &&
		getBalance(root->Left) < 0)
	{
		root->Left = LeftRotate(root->Left);
		return RightRotate(root);
	}
	// Right Right Case
	if (balance < -1 &&
		getBalance(root->Right) <= 0)
		return LeftRotate(root);
	// Right Left Case
	if (balance < -1 &&
		getBalance(root->Right) > 0)
	{
		root->Right = RightRotate(root->Right);
		return LeftRotate(root);
	}
	return root;
}
//3.1.11
//Utility function that checks if a card exist in AVL tree
//Returns 1 if exists
//Returns 0 if not exist
bool Is_Found_In_Playing_Hand(Playing_Hand_Node* root, int Data)
{
	if (root == NULL) return false;
	else if ( Data < root->Data )
	return Is_Found_In_Playing_Hand(root->Left, Data);
	else if( Data > root->Data )
	return Is_Found_In_Playing_Hand(root->Right, Data);
	else if(Data == root->Data) return true;
	else return false;
}
//------------------------------------------------
//4- Game Classes
//4-1 DeckHashTable
//Type: HashTable (array of size 13)
//functionality: Stores number of cards
//Draws card from it according to certain Hashing index
//initially is full
class Deck{
private:
	int DeckCards[13];

public:
	int RemainingCards;
	int Hash_Index(int Card_Number)
	{
		//function that determines hashing index
		return ((Card_Number-1)%13);
	}
	Deck()
	{
		//Default Constructor
		for (int i = 0; i < 13; i++)
		{
			DeckCards[i] = N;
		}
		RemainingCards = 13*N;
	}
	void Reset_Deck()
	{
		//Resets to default after game round ends
		for (int i = 0; i < 13; i++)
		{
			DeckCards[i] = N;
		}
			RemainingCards = 13*N;
	}
	bool IsEmpty()
	{
		//checks if deck is empty, returns 1 if empty and returns 0 if not empty
		if (RemainingCards>0) return false;
		else return true;
	}
	bool CardExist(int Card){
		if (DeckCards[Hash_Index(Card)]>0) return true;
		else return false;
	}
	int DrawCard()
	{
		int Card = Random();
			while (!CardExist(Card))
			{Card = Random();}
			RemainingCards--;
			DeckCards[Card-1]--;
			return Card;
	}
	int NumberDrawCard()
	{
		int Card = NumberRandom();
			while (!CardExist(Card))
			{Card = NumberRandom();}
			RemainingCards--;
			DeckCards[Card-1]--;
			return Card;
	}
	void DisplayDeck()
	{
		for (int i = 0; i < 13; i++)
		{
			Card_Display(i+1);
			cout<<"x "<<DeckCards[i];
			cout<<"\n";
		}

	}
};
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
	Playing_Hand()
	{
		//Default constructor
	Root = NULL;
	Sum = 0;
	Count = 0;
	}
	void ResetHand(){
		//Deletes Hand
		Root = NULL;
		Sum=0;
		Count = 0;
	}
	bool IsFound(int Card){
		return Is_Found_In_Playing_Hand(Root,Card);
	}
	bool IsEmpty(){
		//Check if function is empty
		return(Root == NULL);
	}
	void DrawCard(int Card)
	{
		Root = insert(Root,Card);
		Sum = Sum+Card;
		Count++;
	}
	void DisplayHand()
	{
		Stylised_PreOrder(Root);
		cout<<"\n";
	}
	int PlayCard(int Card)
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

};
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

	int Hash_Index(int Card_Number)
	{
		//function that determines hashing index
		return ((Card_Number-1)%13);
	}
	Floor(){
		//Default Constructor
		FloorCardCount = 0;
		for (int i = 0; i < 13; i++)
		{
			FloorCards[i] = 0;
		}
	}
	void Reset_Floor(){
		//Empty the floor
		FloorCardCount = 0;
		for (int i = 0; i < 13; i++)
		{
			FloorCards[i] = 0;
		}
	}
	bool IsEmpty()
	{
		//checks if deck is empty, returns 1 if empty and returns 0 if not empty
		if (FloorCardCount>0) return false;
		else return true;
	}
	bool CardExist(int Card){
		if (FloorCards[Hash_Index(Card)]>0) return true;
		else return false;
	}
	void PlaceCard(int Card)
	{	//places a card in its Hash index
		FloorCards[Hash_Index(Card)]++;
		FloorCardCount++;
	}
	void DeleteCard(int Card)
	{
		//deletes a card
		if(CardExist(Card))
		{
			FloorCards[Hash_Index(Card)]--;
			FloorCardCount--;
		}
	}
	int EatsAllCards()
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
	void FloorDisplay()
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
	int CardBankCheck (int Card)
	{
		if(CardExist(Card))
		{
			return FloorCards[Hash_Index(Card)];
		}
		else return 0;
	}
	bool MultiFoursCheck(int Card)
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
	bool MultiThreesCheck(int Card)
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
	bool MultiTwosCheck(int Card)
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
	int CardRank(int Card)
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
	int CardBank (int Card)
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
	int MultiFours(int Card)
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
	int MultiThrees(int Card)
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
	int MultiTwos(int Card)
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
};
/*Class Basra
	1.1- Card_Deck
	1.2- Playing_Field
	1.3- Playing_Hand
	1.4- Basra_Player<playing hand[i], score[i]>
	1.5- Basra.play()
	*/
//---------------------------------------
class Basra{
private:
	/*int Number_Of_Players;
	Playing_Hand Player[3];*/
	Playing_Hand Player;
	Playing_Hand AI;
	Deck Kotshena;
	Floor Field;
	int Player_Score;
	int AI_Score;
public:
	Basra()
	{//Default Constructor
	Player = Playing_Hand();
	AI = Playing_Hand();
	Kotshena = Deck();
	Field = Floor();
	Player_Score = 0;
	AI_Score = 0;
	}
	void Reset()
	{//Reset Function for play again option
		Player_Score = 0;
		AI_Score = 0;
		Player.ResetHand();
		AI.ResetHand();
		Kotshena.Reset_Deck();
		Field.Reset_Floor();
	}
	void PlayerDraw()
	{
		for (int i = 0; i < N; i++)
		{
			Player.DrawCard(Kotshena.DrawCard());
		}
	}
	void AIDraw()
	{
		for (int i = 0; i < N; i++)
		{
			AI.DrawCard(Kotshena.DrawCard());
		}
	}
	void FieldDraw()
	{
		for (int i = 0; i < N; i++)
		{
			Field.PlaceCard(Kotshena.DrawCard());
		}
	}
	void Oppening()
	{
		PlayerDraw();
		AIDraw();
		FieldDraw();
	}
	void EndTurn()
	{
		cout<<"\n\nEmpty Hands, Drawing "<<N<<" Cards from Deck...\n";
		PlayerDraw();
		AIDraw();
	}
	void Text()
	{	cout<<"-------------------------------------------------\n\t\t     KOMEY!\n";
		cout<<"-------------------------------------------------\n";
		cout<<"Your Score: "<<Player_Score<<"		AI Score:	"<<AI_Score;
		cout<<"\nCurrent AI Cards: \n(only visible during testing)\n";
		//add comment before the AI Display to hide it from player
		if(AI.Count<=100)AI.DisplayHand();
		else cout<<"supressed, more than 100 cards";
		cout<<"\nCurrent Floor Cards:\n";
		if(Field.FloorCardCount<=100)Field.FloorDisplay();
		else cout<<"supressed, more than 100 cards";
		cout<<endl;
		cout<<"\nCurrent Player Cards:\n";
		if(Player.Count<=100)Player.DisplayHand();
		else cout<<"supressed, more than 100 cards";
		cout<<"-------------------------------------------------\n";
		cout<<"Remaining Cards in Deck:	"<<Kotshena.RemainingCards<<"\n";
	}

	void Play()
	{
		int x = 0;		//player card
		int y = 0;		//AI card
		int z[13] = {0};//Priority Matrix upon which AI decides
		double timestart = 0;
		double clockstart = 0;
		double Time_Elapse_In_Seconds = 0;
		double Clocks_Elapsed_In_Processor_Speed = 0;
		double total_time = 0;
		double total_clocks = 0;
		Oppening();
		while (!(Kotshena.IsEmpty()) || !(Player.IsEmpty()) || !(AI.IsEmpty()))
		{
			while (!(Player.IsEmpty()) || !(AI.IsEmpty()))
			{
				Text();
				cout<<"Your Turn, Pick a Card From 1 to 10 or letter (J,K,Q)\nCard:	";
				x = (Player.PlayCard(CardInput()));
				timestart = Now();
				clockstart = Clocks();
				if (x==11)
				{
					Player_Score++;
					Player_Score += Field.EatsAllCards();
					Text();
				}
				else if (Field.CardRank(x)>0)
				{
					Player_Score++;
					Player_Score += Field.CardBank(x);
					Player_Score += Field.MultiFours(x);
					Player_Score += Field.MultiThrees(x);
					Player_Score += Field.MultiTwos(x);
					Text();
				}
				else
				{
					Field.PlaceCard(x);
					Text();
				}
				Time_Elapse_In_Seconds+=Now()-timestart;
				Clocks_Elapsed_In_Processor_Speed+=Clocks()-clockstart;
				cout<<"Press Enter to Continue Playing Game....";
				cin.getline(dummy_variable,Max_C_String_Size);
				timestart = Now();
				clockstart = Clocks();
				cout<<"AI Turn.... Comparing Card Ranks and possible win\nCard:	";
				for (int i = 0; i < 13; i++)
				{
					if(!(AI.IsFound(i+1))) z[i] = -1;
					else z[i] = Field.CardRank(i+1);
				}
				y = MaxOf(z);
				Card_Display(y);
				AI.PlayCard(y);
				cout<<"\n";
				if (y==11)
				{
					AI_Score++;
					AI_Score += Field.EatsAllCards();
				}
				else if (Field.CardRank(y)>0 && y != 11)
				{
					AI_Score++;
					AI_Score += Field.CardBank(y);
					AI_Score += Field.MultiFours(y);
					AI_Score += Field.MultiThrees(y);
					AI_Score += Field.MultiTwos(y);
				}
				else
				{
					Field.PlaceCard(y);
				}
				Time_Elapse_In_Seconds = Now() - timestart;
				Clocks_Elapsed_In_Processor_Speed = Clocks() - clockstart;
				cout<<"\nTime Elpased in this round: "<<Time_Elapse_In_Seconds<<" seconds";
				cout<<"\nProcessor Clocks Elpased in this round: "<<Clocks_Elapsed_In_Processor_Speed<<" clocks\n";
				total_time+=Time_Elapse_In_Seconds;
				total_clocks+=Clocks_Elapsed_In_Processor_Speed;
				Time_Elapse_In_Seconds = 0 ;
				Clocks_Elapsed_In_Processor_Speed = 0;
			}
			if(!Kotshena.IsEmpty())EndTurn();
		}
		cout<<"\nGame Ended, Remaining cards go to player: ";
		Player_Score+=Field.FloorCardCount;
		cout<<"\nAI Score: "<<AI_Score;
		cout<<"\nPlayer Score: "<<Player_Score;
		if(Player_Score > AI_Score) cout<<"\nCongrats!!! You Win\n";
		else if(Player_Score == AI_Score) cout<<"\nDraw! You got same result as AI\n";
		else cout<<"\nHard luck!:( You Lose\n";
		cout<<"\nTime Elpased in total game computations: "<<total_time<<" seconds";
		cout<<"\nProcessor Clocks Elpased in total game computations: "<<total_clocks<<" clocks\n";
	}
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
	Basra_AI_vs_AI()
	{//Default Constructor
	AI1 = Playing_Hand();
	AI2 = Playing_Hand();
	Kotshena = Deck();
	Field = Floor();
	AI1_Score = 0;
	AI2_Score = 0;
	}
	void Reset()
	{//Reset Function for play again option
		AI1_Score = 0;
		AI2_Score = 0;
		AI1.ResetHand();
		AI2.ResetHand();
		Kotshena.Reset_Deck();
		Field.Reset_Floor();
	}
	void AI1Draw()
	{
		for (int i = 0; i < N; i++)
		{
			AI1.DrawCard(Kotshena.DrawCard());
		}
	}
	void AI2Draw()
	{
		for (int i = 0; i < N; i++)
		{
			AI2.DrawCard(Kotshena.DrawCard());
		}
	}
	void FieldDraw()
	{
		for (int i = 0; i < N; i++)
		{
			Field.PlaceCard(Kotshena.DrawCard());
		}
	}
	void Oppening()
	{
		AI1Draw();
		AI2Draw();
		FieldDraw();
	}
	void EndTurn()
	{
		cout<<"\n\nEmpty Hands, Drawing "<<N<<" Cards from Deck...\n";
		AI1Draw();
		AI2Draw();
	}
	void Text()
	{	cout<<"-------------------------------------------------\n\t\t     KOMEY!\n";
		cout<<"-------------------------------------------------\n";
		cout<<"AI1 Score: "<<AI1_Score<<"		AI2 Score:	"<<AI2_Score;
		cout<<"\nCurrent AI1 Cards: \n";
		//add comment before the AI Display to hide it from player
		if(AI1.Count<=100)AI1.DisplayHand();
		else cout<<"supressed, more than 100 cards";
		cout<<"\nCurrent Floor Cards:\n";
		if(Field.FloorCardCount<=100)Field.FloorDisplay();
		else cout<<"supressed, more than 100 cards";
		cout<<endl;
		cout<<"\nCurrent AI2 Cards:\n";
		if(AI2.Count<=100)AI2.DisplayHand();
		else cout<<"supressed, more than 100 cards";
		cout<<"-------------------------------------------------\n";
		cout<<"Remaining Cards in Deck:	"<<Kotshena.RemainingCards<<"\n";
	}

	void Play()
	{
		int x = 0;		//player card
		int y = 0;		//AI card
		int z[13] = {0};//Priority Matrix upon which AI decides
		double timestart = 0;
		double clockstart = 0;
		double Time_Elapse_In_Seconds = 0;
		double Clocks_Elapsed_In_Processor_Speed = 0;
		double total_time = 0;
		double total_clocks = 0;
		Oppening();
		while (!(Kotshena.IsEmpty()) || !(AI1.IsEmpty()) || !(AI2.IsEmpty()))
		{
			while (!(AI1.IsEmpty()) || !(AI2.IsEmpty()))
			{
				Text();
				timestart = Now();
				clockstart = Clocks();
				cout<<"AI1 Turn.... Comparing Card Ranks and possible win\nCard:	";
				for (int i = 0; i < 13; i++)
				{
					if(!(AI1.IsFound(i+1))) z[i] = -1;
					else z[i] = Field.CardRank(i+1);
				}
				y = MaxOf(z);
				Card_Display(y);
				AI1.PlayCard(y);
				cout<<"\n";
				if (y==11)
				{
					AI1_Score++;
					AI1_Score += Field.EatsAllCards();
				}
				else if (Field.CardRank(y)>0 && y != 11)
				{
					AI1_Score++;
					AI1_Score += Field.CardBank(y);
					AI1_Score += Field.MultiFours(y);
					AI1_Score += Field.MultiThrees(y);
					AI1_Score += Field.MultiTwos(y);
				}
				else
				{
					Field.PlaceCard(y);
				}
				cout<<"AI2 Turn.... Comparing Card Ranks and possible win\nCard:	";
				for (int i = 0; i < 13; i++)
				{
					if(!(AI2.IsFound(i+1))) z[i] = -1;
					else z[i] = Field.CardRank(i+1);
				}
				y = MaxOf(z);
				Card_Display(y);
				AI2.PlayCard(y);
				cout<<"\n";
				if (y==11)
				{
					AI2_Score++;
					AI2_Score += Field.EatsAllCards();
				}
				else if (Field.CardRank(y)>0 && y != 11)
				{
					AI2_Score++;
					AI2_Score += Field.CardBank(y);
					AI2_Score += Field.MultiFours(y);
					AI2_Score += Field.MultiThrees(y);
					AI2_Score += Field.MultiTwos(y);
				}
				else
				{
					Field.PlaceCard(y);
				}
				Time_Elapse_In_Seconds = Now() - timestart;
				Clocks_Elapsed_In_Processor_Speed = Clocks() - clockstart;
				cout<<"\nTime Elpased in this round: "<<Time_Elapse_In_Seconds<<" seconds";
				cout<<"\nProcessor Clocks Elpased in this round: "<<Clocks_Elapsed_In_Processor_Speed<<" clocks\n";
				total_time+=Time_Elapse_In_Seconds;
				total_clocks+=Clocks_Elapsed_In_Processor_Speed;
				Time_Elapse_In_Seconds = 0 ;
				Clocks_Elapsed_In_Processor_Speed = 0;
			}
			if(!Kotshena.IsEmpty())EndTurn();
		}
		cout<<"\nGame Ended, Remaining cards go to AI1: ";
		AI1_Score+=Field.FloorCardCount;
		cout<<"\nAI1 Score: "<<AI1_Score;
		cout<<"\nAI2 Score: "<<AI2_Score;
		if(AI1_Score > AI2_Score) cout<<"\nAI1 wins\n";
		else if(AI1_Score == AI2_Score) cout<<"\nDraw! AI1 same result as AI2\n";
		else cout<<"\nAI2 wins\n";
		cout<<"Cards in hand chosen... N = "<<N<<"\n";
		cout<<"Total Cards in deck: "<<N*13<<" cards \n";
		cout<<"\nTime Elpased in total game computations: "<<total_time<<" seconds";
		cout<<"\nProcessor Clocks Elpased in total game computations: "<<total_clocks<<" clocks\n";
	}
};

//Have Fun :D
//---------------------------------------------
// Driver Code
int main()
{
	Synchronus();
	int Option = 0;
	Intro();
	while(true)
	{
		cout<<"Choose your Komey game mode\n";
		cout<<"1- Player vs AI      (Normal Mode)\n";
		cout<<"2- AI vs AI       (Time Complexity Study Mode)\n";
		cout<<"Option: ";
		Option = PA_Opt_in(2);
		if (Option==1)
		{
			Basra_Intro();
			cin.ignore();
			Basra Game1 = Basra();
			Game1.Play();
			Game1.Reset();
		}

		else if (Option==2)
		{
		cout<<"Enter Number of cards in hand (Complexity Test): ";
		N = PA_Opt_in(100000);
		if(N<4)
		{
			cout<<"minimum cards chosen... N = 4\n";
			N = 4;
		}
		else
		cout<<"cards in hand chosen... N = "<<N<<"\n";
		cout<<"Total Cards in deck: "<<N*13<<" cards \n";
			Basra_AI_vs_AI Game2 = Basra_AI_vs_AI();
			Game2.Play();
			Game2.Reset();
		}

	}
	return 0;
}
