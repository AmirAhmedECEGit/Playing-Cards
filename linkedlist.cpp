#include <iostream>
using namespace std;
//C++ Program for linked lists
class Node {
public:
	int data;
	Node* next;
};

void printList(Node* head_ref)
{
	Node* temp = head_ref;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void push(Node** head_ref, int new_data)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAfter(Node* prev_node, int new_data)
{
	if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL";
        return;
    }
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}
void append(Node** head_ref, int new_data) 
{ 
    Node* new_node = new Node();
    Node* last = *head_ref;
    new_node->data = new_data; 
    new_node->next = NULL; 
    if (*head_ref == NULL) 
    { 
        *head_ref = new_node; 
        return; 
    } 
    while (last->next != NULL)
    {
        last = last->next; 
    }
	last->next = new_node; 
    return; 
} 
void deleteNode(Node** head_ref, int key)
{
    Node* temp = *head_ref;
    Node* prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; 
        delete temp;            
        return;
    }
      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    delete temp;
    }
}
// A structure to represent a stack

 
class StackNode {
public:
    int data;
    StackNode* next;
};
	StackNode* newNode(int data)
{
    StackNode* stackNode = new StackNode();
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}
 
int isEmpty(StackNode* root)
{
    return !root;
}
 
void push(StackNode** root, int data)
{
    StackNode* stackNode = newNode(data);
    stackNode->next = *root;
    *root = stackNode;
    cout << data << " pushed to stack\n";
}
 
int pop(StackNode** root)
{
    if (isEmpty(*root))
        return INT_MIN;
    StackNode* temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
 
    return popped;
}

int peek(StackNode* root)
{
    if (isEmpty(root))
        return INT_MIN;
    return root->data;
}

 

