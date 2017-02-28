/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/
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
	bool isBalanced(TreeNode* root) {
		return balancedHeight(root) >= 0;
	}
	int balancedHeight(TreeNode *root) {
		if (root == NULL) return 0;
		int LeftHeight = balancedHeight(root->left);
		int RightHeight = balancedHeight(root->right);
		if (LeftHeight < 0 || RightHeight < 0 || abs(LeftHeight-RightHeight) > 1) return -1;

		return max(LeftHeight, RightHeight) + 1;
	}
};