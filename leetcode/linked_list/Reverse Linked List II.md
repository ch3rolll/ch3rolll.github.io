# Reverse Linked List II

## Prob

Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example: Given 1->2->3->4->5->nullptr, m = 2 and n = 4,
return 1->4->3->2->5->nullptr.
Note: Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.

## Solution

NOTE: It is not just swap m, n.

## Code

```cpp
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
		i++;
	}
}

void printList(Node* root){
	while(root){
		std::cout<< root<<"->";
		root = root->next;
	}
	std::<<"null"<<std::endl;
}
```