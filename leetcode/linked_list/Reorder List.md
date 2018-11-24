# Reorder List

## Prob

Given a singly linked list L : L0 → L1 → ··· → Ln−1 → Ln,reorder it to: L0 → Ln → L1 → Ln−1 →L2 →Ln−2 →···
You must do this in-place without altering the nodes’ values. 
For example, Given {1,2,3,4}, reorder it to {1,4,2,3}.

## Solution

1. Find the middle point
2. Reverse the right part
3. merge two parts

## Code
```cpp
Node* ReorderList(Node* head){
	Node* dummy;
	dummy -> next = head;
	Node* merge = dummy;

	Node* prev = head;
	int len = 0;
	while(prev){
		prev = prev->next;
		len ++;
	}

	prev = head;
	int k = len/2;

	while(k){
		prev = prev->next;
		k--;
	}

	prev = Reverse(prev);

	while(k<len/2){
		merge -> next = head;
		head = head-> next;
		merge = merge -> next;
		merge -> next = prev;
		prev = prev -> next;
		merge = merge -> next;
	}
	return dummy -> next;
}

Node* Reverse(Node* head){
	if (head == nullptr || head->next == nullptr) return;

	Node* prev = head;

  	for (ListNode *curr = head->next, *next = curr->next; 
  		curr;
      	prev = curr, curr = next, next = next ? next->next : nullptr) {
          curr->next = prev;
  	}

  	head->next = nullptr;
  	return prev;
}
```


```cpp
void reorderList(ListNode *head) {
	  if (head == nullptr || head->next == nullptr) return;
	  ListNode *slow = head, *fast = head, *prev = nullptr;
	  while (fast && fast->next) {
	      prev = slow;
	      slow = slow->next;
	      fast = fast->next->next;
	  }
	  prev->next = nullptr; // cut at middle
	  slow = reverse(slow);
	  // merge two lists
	  ListNode *curr = head;
	  while (curr->next) {
	      ListNode *tmp = curr->next;
	      curr->next = slow;
	      slow = slow->next;
	      curr->next->next = tmp;
	      curr = tmp;
	  }
	  curr->next = slow;
}
```