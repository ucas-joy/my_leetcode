/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	/*vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>>result;
		traverse(root, 1, result);
		return result;

	}
	void traverse(TreeNode *root, size_t level, vector<vector<int>>&result){
		if (!root) return;
		if (level > result.size())
		{
			result.push_back(vector<int>());
		}
		result[level - 1].push_back(root->val);
		traverse(root->left, level + 1, result);
		traverse(root->right, level + 1, result);
	}*/
//·½·¨¶þ
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>>result;
		vector<int>res;
		if (root == NULL)
			return result;
		queue<TreeNode*>q;
		TreeNode *p = root;
		q.push(p);
		while (!q.empty()){
			int size = q.size();
			for (int i = 0; i < size; ++i){
				TreeNode *tmp_node = q.front();
				q.pop();
				res.push_back(tmp_node->val);
				if (tmp_node->left != NULL){
					q.push(tmp_node->left);
				}
				if (tmp_node->right != NULL){
					q.push(tmp_node->right);
				}
			}
			result.push_back(res);
			res.clear();
		}
		return result;
	}
};