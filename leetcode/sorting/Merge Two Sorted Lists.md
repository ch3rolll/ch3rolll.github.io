# Merge Two Sorted Lists

## Prob
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

## Code

```cpp
ListNode* MergeTwoSorted(ListNode* l1, ListNode* l2){
	if (l1 == nullptr) return l2;
	if (l2 == nullptr) return l1;

	ListNode dummy(-1);
	ListNode *p = &dummy;

	while(l1 && l2){
		if (l1->val <= l2 -> val){
			p->next = l1;
			l1 = l1 -> next;
		} else{
			p->next = l2;
			l2 = l2 -> next;
		} 

		p = p -> next;
	}

	if(l1) p -> next = l1;
	if(l2) p -> next = l2;

	return dummy.next;
}
```