# Linked List Cycle II

## Prob
Given a linked list, return the node where the cycle begins. If there is no cycle, return null. Follow up: Can you solve it without using extra space?

## Solution

2s = s + nr

x+a = s = nr = (n-1)r + l-x

x = (n-1)r + l-x-a

## Code

```cpp
Node* HasCycle(Node* head){
	Node *fast = head, *slow = head;
	Node* slow2 = head;
    while (fast && fast->next) {
          slow = slow->next;
          fast = fast->next->next;
          if (slow == fast){
          	while(slow2 != slow){
          		slow = slow -> next;
          		slow2 = slow2 -> next;
          	}
          	return slow2;
          }
    }
     return nullptr;
}
```