# Construct Binary Tree from Preorder and Inorder Traversal

## Prob
Given preorder and inorder traversal of a tree, construct the binary tree. Note: You may assume that duplicates do not exist in the tree.

##Code
```cpp
TreeNoe* buildTree(std::vector<int> &preorder, std::vector<int>& inorder){
	return buildTree (preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
}

template <typename InputIterator>
TreeNode* buildTree(InputIterator pre_first, InputIterator pre_last,
					InputIterator in_first, InputIterator in_last){
	if(pre_first == pre_last) return nullptr;
	if(in_first == in_last) return nullptr;

	auto root = new TreeNode(*pre_first);

	auto inRootPos = std::find(in_first, in_last, *pre_first);
	auto leftSize = std::distance(in_first, inRootPos);

	root -> left = buildTree(std::next(pre_first), std::next(pre_first, left_size),
							in_first, std::prev(inRootPos));
	root -> right = buildTree(std::next(pre_first, left_size+1), pre_last,
							std::next(inRootPos), in_last);

	return root;
}

```