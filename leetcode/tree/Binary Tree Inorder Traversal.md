# Binary Tree Inorder Traversal

## Code

```cpp
std::vector<int> inorderTraversal(TreeNode* root){
	std::vector<int> result;

	std::stack<const TreeNode *> stk;

	if(!root) return result;
	s.push(root);

	while(!stk.empty()){
		TreeNode* temp = stk.top();

		if(temp -> left) stk.push(temp->left);
		else {
			stk.pop();
			result.push_back(temp->val);
			if(temp->right) stk.push(temp->right);
		}
	}
	return result;
}
```


Solution 2:
```cpp
std::vector<int> inorderTraversal(TreeNode* root){
	std::vector<int> result;

	std::stack<const TreeNode *> stk;

	if(!root) return result;
	s.push(root);

	TreeNode *p = root;

	while(!stk.empty() || p != nullptr){
		if(p){
			stk.push(p);
			p = p ->left;
		}else{
			p = s.top();
			s.pop();
			result.push_back(p->val);
			p = p ->right;
		}
	}
	return result;
}
```