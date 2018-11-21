# Rotate List

## Prob

Given a list, rotate the list to the right by k places, where k is non-negative.
For example: Given 1->2->3->4->5->nullptr and k = 2, return 4->5->1->2->3->nullptr.

## Solution

Link the last element with the first one to make it a circle. Find the (n-k)th, break the circle here

## Code

```cpp
void RotateList(Node* &root, int k){
	Node* dummy = newNode(-1);

	dummy-> next = root;

	int n = 0;

	while (root){
		root = root->next;
		n++;
	}

	root -> next = dummy->next;

	root = root->next;

	while( k < n){
		k++;
		root = root->next;
	}

	root -> next = nullptr;

}
```