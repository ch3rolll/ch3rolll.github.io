# Path Sum II

## Prob

Following Path Sum I. Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum. For example: Given the below binary tree and sum = 22,

## Code

```cpp
void PathSum(TreeNode* root, int sum, std::vector<int>& cur, std::vector<std::vector<int>>& result){
	if (root == nullptr) return;

	cur.push_back(root);

	if(root -> left == nullptr && root -> right == nullptr){
		if(root -> val == sum){
			result.push_back(cur);
		}
	}

	PathSum(root->left, sum-root->val, cur, result);
	PathSum(root->right, sum-root->val, cur, result);
	cur.pop_back();
}
```