# Remove Duplicates from Sorted List

## Prob

Given a sorted linked list, delete all duplicates such that each element appear only once. For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.

## Solution


## Code

```cpp
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct Node 
{ 
	int data; 
	struct Node* next; 
}; 

/* Function to create a new node with given data */
struct Node *newNode(int data) 
{ 
	struct Node *new_node = new Node; 
	new_node->data = data; 
	new_node->next = nullptr; 
	return new_node; 
}

/* Function to insert a node at the beginning of the Singly Linked List */
void push(struct Node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = newNode(new_data); 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

void printList(Node* root){
    while(root != nullptr){
        std::cout<<root->data<<"->";
        root = root->next;
    }
    std::cout<<std::endl;
}

void ReverseLinkedList(Node* &root, int m, int n){

	Node* prev = root;

	int i = 1;

	while(i < m-1){ 
		prev = prev->next;
		i++;
	}
	// when i==m-1
	Node* cur = prev -> next;
	Node* temp = cur->next;

	// Root is at m
	while(i < n-1){
		cur->next = temp->next;
		temp->next = prev->next;
		prev->next = temp;
		
		temp = cur->next;
		i++;
	}
}

int main(void) 
{ 
	struct Node* res = nullptr; 
	struct Node* first = nullptr; 
	struct Node* second = nullptr; 

	// create first list 7->5->9->4->6 
	push(&first, 6); 
	push(&first, 4); 
	push(&first, 9); 
	push(&first, 5); 
	push(&first, 7); 
	std::cout<<"First List is "<<std::endl; 
	printList(first); 


	// Add the two lists and see result 
	ReverseLinkedList(first, 2,4); 
	printf("Resultant list is "); 
	printList(first); 

    return 0; 
} 

```
