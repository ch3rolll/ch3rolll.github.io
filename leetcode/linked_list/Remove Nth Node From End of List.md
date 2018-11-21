# Remove Nth Node From End of List

## Prob

Given a linked list, remove the nth node from the end of list and return its head. For example, Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5. Note:
• Given will always be valid. • Try to do this in one pass.


## Code

```cpp
#include <vector>

void RemoveNth(Node* &root, int n){

	Node* p = root;

	std::vector<Node*> vec;

	int len = 0;

	while(p != nullptr){
		vec.push_back(p);
		p = p->next;
		len++;
	}

	if (n >= len){
		auto temp = root->next;
		delete root;
		root = temp;
	}else{
		auto temp = vec[len-n-1];
		auto cur = temp->next;
		temp -> next = cur->next;
		delete cur;
	}

}

```

