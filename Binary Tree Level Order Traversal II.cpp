/*Given a binary tree, return the bottom - up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example :
Given binary tree[3, 9, 20, null, null, 15, 7],
     3
    / \
   9  20
  / \
15   7
return its bottom - up level order traversal as :
[
	[15, 7],
	[9, 20],
	[3]
]
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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> result;
		traverse(root, 1, result);
		reverse(result.begin(), result.end());
		return result;

	}
	void traverse(TreeNode *root, size_t level, vector<vector<int>> &result) {
		if (!root) return;
		if (level > result.size()) {
			result.push_back(vector<int>());
		}
		result[level - 1].push_back(root->val);
		traverse(root->left, level + 1, result);
		traverse(root->right, level + 1, result);
	}
};