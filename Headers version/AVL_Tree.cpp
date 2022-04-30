#include "AVL_Tree.h"

//3- Data Structures
//3.1- AVL Tree
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