# Reverse Nodes in k-Group

## Prob

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is. You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.
For example, Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

## Solution

for every k elements, do reverse.


## Code

```cpp
Node *reverseKGroup(Node *head, int k) {

  if (head == nullptr || head->next == nullptr || k < 2) return head;
  Node* dummy = newNode(-1);
  dummy->next = head;
  for(Node *prev = dummy, *end = head; end; end = prev->next) {
      for (int i = 1; i < k && end; i++)
		end = end->next;
	  if (end == nullptr) break; // 􏱢􏲡 k 􏱾
      prev = reverse(prev, prev->next, end);
  }
  return dummy->next;
}
// prev 􏰓 first 􏲢􏱫􏱾􏲣􏲤, [begin, end] 􏲥􏰑􏰒􏰆􏲦􏲧􏰂􏲨􏲩􏱢􏰎 null // 􏲪􏰕􏲫􏰙􏲃􏰳􏲬􏲭􏰫 1 􏱾􏲣􏲤
Node* reverse(Node *prev, Node *begin, Node *end) {
  Node *end_next = end->next;
  for (Node *p = begin, *cur = p->next, *next = cur->next;
          cur != end_next;
          p = cur, cur = next, next = next ? next->next : nullptr) {
      cur->next = p;
  }
  begin->next = end_next;
  prev->next = end;
  return begin;
}
```

```cpp
Node* reverseKGroup(Node* head, int k){
	Node dummy = {-1, head};

	for (Node* prev = dummy, *end = head; end; end=prev->next){
		for(int i = 1; i < k && end; i++) end = end->next;
		if(end == nullptr) break;
		prev = reverse(prev, prev->next, end);
	}

	return dummy.next;
}

Node* reverse(Node* prev, Node* begin, Node* end){
	Node* end_next = end->next;

	for(Node* p = begin, *cur = p->next, *next = cur->next;
		cur != end_next;
		p = cur, cur = next, next = next?next->next:nullptr){

		cur -> next = p;
	}

	begin -> next = end_next;
	prev->next = end;
	return begin;
}

```