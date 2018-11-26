# Symmetric Tree

## Prob

Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

## Code

```cpp
bool isSymmetric(TreeNode* root){
	if (root == nullptr) return true;
	return isSymmetric(root -> left, root -> right);
}

bool isSymmetric(TreeNode* l, TreeNode* r){
	if (l == nullptr && r == nullptr) return true;
	if(l == nullptr || r == nullptr) return false;

	return l->val == r -> val &&
			isSymmetric(l -> left, l -> right) &&
			isSymmetric(r -> left, r -> right);
}
```