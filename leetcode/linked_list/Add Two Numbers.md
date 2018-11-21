# Add Two Numbers

## Prob

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4) Output: 7 -> 0 -> 8


## Solution
1. Have an int carry to record if > 10
2. If one of those two linked list is empty, copy the rest
3. If they are all empty && carry > 0, have a new node in the end.


## Code

```cpp
template<class T>
class Node{
    public:
        Node();
        Node(const T& item, Node<T>* ptrnext = nullptr);
        T data;
        // access to the next node
        Node<T>* NextNode();
        // list modification methods
        void InsertAfter(Node<T>* p);
        Node<T>* DeleteAfter();
        Node<T>* GetNode(const T& item, Node<T>* nextptr = nullptr);
    private:

        Node<T> * next;
};

template<class T>
void Node::Node(const T& item, Node<T>* ptrnext){
	this -> data = item;
	this -> next = ptrnext;
}


template<class T>
void Node::InsertAfter(Node<T>* p){
	p -> next = this -> next;
	this -> next = p;
}

template<class T>
Node<T>* Node::DeleteAfter(){
	Node<T>* tempNode = next;
	if(this -> next != nullptr){
		this -> next = this->next->next;
	}
	this -> next = nullptr;

	return tempNode;
}

template<class T>
Node<T>* Node::Reverse(){
	Node<T>* tempNode = next;
	if(this -> next != nullptr){
		this -> next = this->next->next;
	}
	this -> next = nullptr;

	return tempNode;
}
```


```cpp
/* Linked list node */
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

/* Adds contents of two linked lists and return the head node of resultant list */
struct Node* addTwoLists (struct Node* first, struct Node* second) 
{ 
	struct Node* res = nullptr; // res is head node of the resultant list 
	struct Node *temp, *prev = nullptr; 
	int carry = 0, sum; 

	while (first != nullptr || second != nullptr) //while one of  lists exist 
	{ 
		// Calculate value of next digit in resultant list. 
		// The next digit is sum of following things 
		// (i) Carry 
		// (ii) Next digit of first list (if there is a next digit) 
		// (ii) Next digit of second list (if there is a next digit) 
		sum = carry + (first? first->data: 0) + (second? second->data: 0); 

		// update carry for next calulation 
		carry = sum / 10;

		// update sum if it is greater than 10 
		sum = sum % 10; 

		// Create a new node with sum as data 
		temp = newNode(sum); 

		// if this is the first node then set it as head of the resultant list 
		if(res == nullptr) 
			res = temp; 
		else // If this is not the first node then connect it to the rest. 
			prev->next = temp; 

		// Set prev for next insertion 
		prev = temp; 

		// Move first and second pointers to next nodes 
		if (first) first = first->next; 
		if (second) second = second->next; 
	} 

	if (carry > 0) temp->next = newNode(carry); 

	// return head of the resultant list 
	return res; 
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
	printf("First List is "); 
	printList(first); 

	// create second list 8->4 
	push(&second, 4); 
	push(&second, 8); 
	printf("Second List is "); 
	printList(second); 

	// Add the two lists and see result 
	res = addTwoLists(first, second); 
	printf("Resultant list is "); 
	printList(res); 

return 0; 
} 


```
