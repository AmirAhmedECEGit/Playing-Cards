#pragma once
#include <iostream>
#include<ctime>
#include"Macros.h"
using namespace std;

//2- Utility Functions
//2.1- Elapsed_Time_In_Seconds
double Now();
//2.2- Elapsed number of processor clocks
double Clocks();
//2.3- Code to randomize number
int Random();
int NumberRandom();
void Synchronus();
//2.4- Code to display playing cards as stylised model where 1->10 the J = 11, Q = 12, K = 13
void Card_Display(int x);
//2.5- Code to convert user input into numbers and reject bad input
bool Find (char str[], char sub[]);
bool IsNumber(char Temp[]);
bool IsLetter(char Temp[]);
int CardInput();

//2.6- A utility function to get Maximum of two integers
int Max(int a, int b);
//2.7- Option checking, number input function
int  PA_Opt_in (int n);
//2.8- Find Biggest element in 3 elements
int Biggest(int x,int y,int z);

//2.9- Find Biggest element in an array
int MaxOf(int arr[13]);

//2.10- Intro Text Display
void Intro();
void Basra_Intro();
