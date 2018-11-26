# Binary Tree Level Order Traversal

## Prob


Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by level).
For example: Given binary tree {3,9,20,#,#,15,7},

  3
  /\
 9 20
   /\ 
  15 7
return its level order traversal as:
[ [3],
[9,20],
[15,7] ]

## Code

Not using recursion

```cpp

vector<vector<int> > levelOrder(TreeNode* root, int level){
	vector< vector<int> > result;

	// Just push the prev level to current and next for the next level
	queue< TreeNode* > current, next;

	if(root == nullptr) return result;
	else current.push(root);

	while(!current.empty()){
		vector<int> level;

		while(!current.empty()){
			TreeNode* node = current.front();
			current.pop();
			level.push_back(node -> val);

			if(node->left != nullptr) next.push(node -> left);
			if(node -> right != nullptr) next.push(node -> right);
		}

		result.push_back(level);
		swap(next, current);
	}

	return result;
}
```