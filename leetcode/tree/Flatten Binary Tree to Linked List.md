# Flatten Binary Tree to Linked List

## Prob

Given a binary tree, flatten it to a linked list in-place. For example, Given
	  ```
	   1 
	  / \ 
	 2   5
	/\    \
   3  4    6
   ```
The flattened tree should look like:
```
1 
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
```

## Code

```cpp

void flatten(TreeNode* root){
	flatten(root, nullptr);
}

TreeNode* flatten(TreeNode* root, TreeNode* tail){
	if(root == nullptr) return tail;

	root -> right = flatten(root -> left, flatten(root -> right, tail));
	root-> left = nullptr;

	return root;
}
