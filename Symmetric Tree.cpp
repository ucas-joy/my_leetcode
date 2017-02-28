/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

     1
    / \
   2   2
  / \ / \
 3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
  1
 / \
2   2
\   \
3    3
Note:
Bonus points if you could solve it both recursively and iteratively
*/


#include<iostream>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) {
			return true;
	     }
		return IsEqual(root->left, root->right);
	}
	bool IsEqual(TreeNode *p, TreeNode *q) {
		if (p == NULL && q == NULL) {
			return true;
		}
		if (p == NULL || q == NULL) {
			return false;
		}
		return p->val == q->val && IsEqual(p->left, q->right) && IsEqual(p->right, q->left);
   }
};