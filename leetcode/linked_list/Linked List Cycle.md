# Linked List Cycle

## Prob

Given a linked list, determine if it has a cycle in it. Follow up: Can you solve it without using extra space?

## Solution

Have two pointers, one slow and another fast. If they meet each other at some point, then there is a cycle.


## Code
```cpp
bool HasCycle(Node* head){
	Node *fast = head, *slow = head;

    while (fast && fast->next) {
          slow = slow->next;
          fast = fast->next->next;
          if (slow == fast) return true;
    }
     return false;
}
```