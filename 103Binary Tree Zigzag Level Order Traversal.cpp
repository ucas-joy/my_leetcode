/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its zigzag level order traversal as:
[
[3],
[20,9],
[15,7]
]
Subscribe to see which companies asked this question
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
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>>result;
		vector<int>res;
		if (root == NULL)
			return result;
		queue<TreeNode*>q;
		TreeNode*p = root;
		q.push(root);
		int flag = 0;
		while (!q.empty()){
			int size = q.size();
			for (int i = 0; i < size; ++i){
				TreeNode* tmp_node = q.front();
				q.pop();
				res.push_back(tmp_node->val);
				if (tmp_node->left != NULL){
					q.push(tmp_node->left);
				}
				if (tmp_node->right != NULL){
					q.push(tmp_node->right);
				}
			}
			flag++;
			if (flag % 2 != 0){
				reverse(res.begin(), res.end());
			}
			
			result.push_back(res);
			res.clear();
		}
		return result;
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////½¨Ê÷
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
int main()
{
	int a[6] = { 1,2,3,4,5,6 };
	int b[6] = { 3,2,4,1,6,5 };
	vector<int>pre(a, a + 6);
	vector<int>in(b, b + 6);
	Solution sol;
	TreeNode *root = sol.buildTree(pre, in);
	vector<vector<int>>res = sol.zigzagLevelOrder(root);

	return 0;
}
