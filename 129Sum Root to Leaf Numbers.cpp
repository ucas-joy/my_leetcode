/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

   1
  / \
 2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
	int ans = 0;
	int sumNumbers(TreeNode* root) {
		if (root == NULL) return 0;
		depthSearch(root, 0);
		return ans;
	}
	void depthSearch(TreeNode* root, int number)
	{
		number = number * 10 + root->val;
		if (root->left == NULL && root->right == NULL)
		{
			ans += number;
			return;
		}
		if (root->left != NULL) depthSearch(root->left, number);
		if (root->right != NULL) depthSearch(root->right, number);
	}
		

//////////////////////////////////////////////////////////////////////////////////////////
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
int main129()
{
	int a[5] = { 1,2,3,4,5 };
	int b[5] = { 3,2,4,1,5 };
	vector<int>pre(a, a + 5);
	vector<int>in(b, b + 5);
	Solution sol;
	TreeNode *root = sol.buildTree(pre, in);
	int sum = sol.sumNumbers(root);
	cout << sum << endl;
	return 0;
}
