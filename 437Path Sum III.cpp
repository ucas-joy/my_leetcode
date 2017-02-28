/*
You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

        10
	   /  \
	  5   -3
	 / \    \
	3   2   11
   / \   \
  3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11
Subscribe to see which companies asked this question
*/

/*
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };*/

#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL)
			return 0;
		return dfs(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}
	int dfs(TreeNode *root, int total,int sum)
	{
		if (root == NULL)
			return 0;
		int left = 0, right = 0, mid = 0;
		if (total + root->val == sum) mid = 1;
		if (root->left) left = dfs(root->left, total + root->val, sum);
		if (root->right) right = dfs(root->right, total + root->val, sum);
		return left + right + mid;
	}
/////////////////////////////////////////////////////
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int l1 = 0, l2 = 0;
		int h1 = preorder.size() - 1, h2 = inorder.size() - 1;
		if (h1 == -1) {
			return NULL;
		}
		TreeNode *root = Construct(preorder, inorder, l1, h1, l2, h2);
		return root;


	}
	TreeNode* Construct(vector<int>&preorder, vector<int>&inorder, int l1, int h1, int l2, int h2) {
		TreeNode* root = new TreeNode(preorder[l1]);
		int i = distance(inorder.begin(), find(inorder.begin(), inorder.end(), root->val));
		int llen = i - l2;
		int rlen = h2 - i;
		if (llen) {
			root->left = Construct(preorder, inorder, l1 + 1, l1 + llen, l2, l2 + llen - 1);
		}
		else {
			root->left = NULL;
		}
		if (rlen) {
			root->right = Construct(preorder, inorder, h1 - rlen + 1, h1, h2 - rlen + 1, h2);
		}
		else {
			root->right = NULL;
		}
		return root;
	}

};
