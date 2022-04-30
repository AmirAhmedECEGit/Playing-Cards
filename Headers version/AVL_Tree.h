#pragma once
#include<iostream>
#include "Macros.h"
#include "Utility.h"
using namespace std;
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
int Hand_AVL_Height(Playing_Hand_Node *N);
//3.1.2 A utility function to check if tree is empty
bool IsEmptyHand(Playing_Hand_Node *Root);
//3.1.3
// Helper function that allocates a
//new Playing_Hand_Node with the given Data and
//NULL Left and Right pointers.
Playing_Hand_Node* newPlaying_Hand_Node(int Data);
//3.1.4
// A utility function to Right
// rotate subtree rooted with y
// See the diagram given above.
Playing_Hand_Node *RightRotate(Playing_Hand_Node *y);
//3.1.5
// A utility function to Left
// rotate subtree rooted with x
// See the diagram given above.
Playing_Hand_Node *LeftRotate(Playing_Hand_Node *x);
//3.1.6
//Utility to check Balance for AVL tree
int getBalance(Playing_Hand_Node *N);
//3.1.7
// Recursive function to insert a Data
// in the subtree rooted with Playing_Hand_Node and
// returns the new root of the subtree.
// 1. Perform the normal BST insertion
Playing_Hand_Node* insert(Playing_Hand_Node* Playing_Hand_Node, int Data);
//3.1.8
// A utility function to print Stylised_PreOrder [* 1 ]
// traversal of the tree.
// The function also prints Hand_AVL_Height
// of every Playing_Hand_Node
void Stylised_PreOrder(Playing_Hand_Node *root);
//3.1.9 loop down to find the Leftmost leaf
Playing_Hand_Node * minValuePlaying_Hand_Node(Playing_Hand_Node* Temp);
//3.1.10
// Recursive function to delete an AVL Node
// with given Data from subtree with
// given root. It returns root of the
// modified subtree.
Playing_Hand_Node* deletePlaying_Hand_Node(Playing_Hand_Node* root, int Data);
//3.1.11
//Utility function that checks if a card exist in AVL tree
//Returns 1 if exists
//Returns 0 if not exist
bool Is_Found_In_Playing_Hand(Playing_Hand_Node* root, int Data);