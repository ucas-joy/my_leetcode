/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

     1
    / \
   2   5
  / \   \
 3   4   6
The flattened tree should look like:
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
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void flatten(TreeNode* root) {
		TreeNode*now = root;
		while (now)
		{
			if (now->left)
			{
				TreeNode *pre = now->left;
				while (pre->right)
				{
					pre = pre->right;
				}
				pre->right = now->right;
				now->right = now->left;
				now->left = NULL;
			}
			now = now->right;
		}
	}
};