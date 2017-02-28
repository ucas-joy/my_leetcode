/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root."
Besides the root, each house has one and only one parent house. After a tour, the smart thief 
realized that "all houses in this place forms a binary tree". It will automatically contact the police
if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:
	 3
    / \
   2   3
    \   \
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> getMoney(TreeNode *node){
		vector<int> ret(2,0);
		if (!node)return ret;
		vector<int>lRet = getMoney(node->left);
		vector<int>rRet = getMoney(node->right);
		ret[0] = lRet[1] + rRet[1] + node->val;
		ret[1] = max(lRet[0], lRet[1]) + max(rRet[0], rRet[1]);
		return ret;
	}
	int rob(TreeNode* root) {
		vector<int>ret = getMoney(root);
		return max(ret[0], ret[1]);
	}
};


















/*
// 0 表示取， 1表示不取
class Solution {
	vector<int> getMoney(TreeNode* node) {
		vector<int> ret(2, 0);
		if (!node) return ret;
		vector<int> lRet = getMoney(node->left);
		vector<int> rRet = getMoney(node->right);
		ret[0] = lRet[1] + rRet[1] + node->val;
		ret[1] = max(lRet[0], lRet[1]) + max(rRet[0], rRet[1]);
		return ret;
	}
public:
	int rob(TreeNode* root) {
		vector<int> ret = getMoney(root);
		return max(ret[0], ret[1]);
	}
};
*/