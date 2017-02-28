/*
Tree Depth-first Search
Show Similar Problems
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections.
The path must contain at least one node and does not need to go through the root.

For example:
Given the below binary tree,

	1
   / \
  2  3
Return 6.

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
	int result =INT_MIN;
	int maxPathSum(TreeNode* root) {
		dfs(root, result);
		return result;
		
	}
	int dfs(TreeNode *root, int &result) {
		if (root == NULL)
			return 0;
		else
		{
			int leftSum = dfs(root->left, result);
			int rightSum = dfs(root->right, result);

			leftSum = leftSum > 0 ? leftSum : 0;
			rightSum = rightSum > 0 ? rightSum : 0;

			result = max(result, root->val + leftSum + rightSum);
			return root->val + max(leftSum, rightSum);
		}
	}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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

int main123123()
{
	int a[2] = { 1,2 };
	int b[2] = { 2,1 };
	vector<int>pre(a, a + 2);
	vector<int>in(b, b + 2);
	Solution sol;
	TreeNode *root = sol.buildTree(pre, in);
	int t = sol.maxPathSum(root);
	cout << t << endl;
	return 0;
}