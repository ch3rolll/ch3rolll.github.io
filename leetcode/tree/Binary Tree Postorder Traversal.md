# Binary Tree Postorder Traversal

## Code

```cpp
std::vector<int> PostorderTraversal(TreeNode* root){
	std::vector<int> result;
	std::stack<const TreeNode*> s;

	if(root == nullptr) return result;
	s.push(root);

	const TreeNode *p = root, *q = nullptr;


	while(!s.empty() ){
		while(p!=nullptr){
			s.push(p);
			p = p -> left;
		}

		q = nullptr;

		while(!s.empty()){
			p = s.top();
			s. pop();

			if(p -> right == q){
				result.push_back(p -> val);
				q = p;
			} else{
				s.push(p);
				p = p -> right;
				break;
			}
		}
	}
	return result

}
```