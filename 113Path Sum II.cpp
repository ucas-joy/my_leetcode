/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
		5
	   / \
      4   8
     /   / \
    11  13  4
   /  \    / \
  7    2  5   1
return
[
[5,4,11,2],
[5,8,4,5]
]
Subscribe to see which companies asked this question
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>>res;
		if (root == NULL)
			return res;
		TreeNode*p = root;
		vector<int>tmp;
		int total = 0;
		stack<TreeNode*>st;
		while (p || !st.empty()){
			if (p) {
				st.push(p);
				tmp.push_back(p->val);
				total = total + p->val;
			}
			else
			{
				if (total == sum){
					res.push_back(tmp);
				}
				p = st.top();
				st.pop();
				if (p->right == NULL)
				{
					total = total - p->val;
					tmp.pop_back();
				}	
				p = p->right;
			}
		}
		return res;
	}
	

};
*/
class Solution {
public:
	vector<vector<int>>res;
	void dfs(TreeNode* root, int sum, vector<int>&cur) {
		if (!root) return;
		cur.push_back(root->val);
		if (!root->left && !root->right && root->val == sum) {
			res.push_back(cur);
			return;
		}
		dfs(root->left, sum - root->val, cur);
		dfs(root->right, sum - root->val, cur);
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root == NULL) return res;
		dfs(root, sum, vector<int> (0));
		return res;
	}
};
