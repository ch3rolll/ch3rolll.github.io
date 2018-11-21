# Partition List

## Prob

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions. For example, Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.

## Solution

1. Linear scan and put the smaller part in a list and >= part in a right list.
2. Combine left and right

## Code

```cpp
Node* PartitionList(Node* root, int x){
	Node* left_dummy = newNode(-1);
	Node* right_dummy = newNode(-1);

	auto left = left_dummy;
	auto right = right_dummy;

	Node* cur = root;

	while(curr){
		if(cur->val < x){
			left -> next = cur;
			left = left->next;
		}else{
			right -> next = cur;
			right = right -> next;
		}
		cur = cur -> next;
	}

	left -> next = right_dummy -> next;
	right -> next = nullptr
	return left_dummy->next;
}

```