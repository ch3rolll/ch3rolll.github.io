# Validate Binary Search Tree

## Prob

Given a binary tree, determine if it is a valid binary search tree (BST). Assume a BST is defined as follows:
• The left subtree of a node contains only nodes with keys less than the node’s key.
• The right subtree of a node contains only nodes with keys greater than the node’skey. 
• Both the left and right subtrees must also be binary search trees.

## Code
```cpp
bool isValidateBST(TreeNode* root){
	if (root == nullptr) return true;

	int left = (root->left == nullptr)? INT_MIN:root->left->val;
	int right = (root->right == nullptr)? INT_MAX:root->right->val;

	return (left <= root->val) && (right >= root -> val) &&
			isValidateBST(root->left) && isValidateBST(root->right);
}
```