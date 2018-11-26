# Binary Tree Preorder Traversal

## Tree

```cpp
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

```

## Code

- Stack

```cpp
std::vector<int> preorderTraversal(TreeNode *root){
	std::vector<int> result;

	std::stack<const TreeNode*> stk;

	if(root) stk.push(root); 

	while(!stk.empty()){
		TreeNode *tmp = stk.top();
		result.push_back(tmp->val);

		stk.pop();

		if(tmp->right) stk.push(tmp->right);
		if(tmp->left) stk.push(tmp->left);
	}

	return result
}
```