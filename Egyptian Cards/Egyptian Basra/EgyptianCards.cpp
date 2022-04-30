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
#include "Macros.h"
char dummy_variable [Max_C_String_Size];
#include "Utility.h"
#include "AVL_Tree.h"
#include "Playing_Hand.h"
#include "Floor.h"
#include "Komey.h"
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
			cin.getline(dummy_variable,Max_C_String_Size);
			cin.ignore();
			Basra Game1 = Basra();
			Game1.Play();
			Game1.Reset();
		}

		else if (Option==2)
		{
			parameter_change();
			Basra_AI_vs_AI Game2 = Basra_AI_vs_AI();
			Game2.Play();
			Game2.Reset();
		}

	}
	return 0;
}
