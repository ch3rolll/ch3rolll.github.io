# Minimum Depth of Binary Tree

## Prob

Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

## Code

```cpp
int minDepth(Node *root) { 
    // Corner case. Should never be hit unless the code is  
    // called on root = NULL 
    if (root == NULL) 
        return 0; 
  
    // Base case : Leaf Node. This accounts for height = 1. 
    if (root->left == NULL && root->right == NULL) 
       return 1; 
  
    // If left subtree is NULL, recur for right subtree 
    if (!root->left) 
       return minDepth(root->right) + 1; 
  
    // If right subtree is NULL, recur for left subtree 
    if (!root->right) 
       return minDepth(root->left) + 1; 
  
    return min(minDepth(root->left), minDepth(root->right)) + 1; 
} 
```