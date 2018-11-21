# Swap Nodes in Pairs

## Prob

Given a linked list, swap every two adjacent nodes and return its head.

For example, Given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


## Code

```cpp
void SwapNode(Node* &root){
	if(!root || !root->next) return;

	Node* dummy = newNode(-1);

	dummy -> next = root;
	Node* prev = dummy;
	Node* cur = root;
	Node* temp;

	while(cur && cur->next){
		temp = cur->next;
		prev->next = temp;
		cur->next = temp -> next;
		temp -> next = cur;

		prev = cur;
		cur = cur -> next;
	}
	
	root = dummy -> next;
}
```
