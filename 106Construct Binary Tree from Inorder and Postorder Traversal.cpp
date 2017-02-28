#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int l1 = 0, l2 = 0;
		int h1 = postorder.size()-1, h2 = inorder.size()-1;
		if (h1 == -1)
			return NULL;
		TreeNode* root = Construct(inorder, postorder, l1, h1, l2, h2);
		return root;
	}
	TreeNode* Construct(vector<int>& inorder, vector<int>& postorder, int l1, int h1, int l2, int h2)
	{
		TreeNode *root = new TreeNode(postorder[h1]);
		int i = distance(inorder.begin(), find(inorder.begin(), inorder.end(), root->val));
		int llen = i - l2;
		int rlen = h2 - i;
		if (llen)
		{
			root->left = Construct(inorder, postorder, l1, l1 + llen-1 , l2, l2 + llen - 1);
		}
		else
		{
			root->left = NULL;
		}
		if (rlen)
		{
			root->right = Construct(inorder, postorder, h1-rlen , h1-1, h2 - rlen + 1, h2);
		}
		else
		{
			root->right = NULL;
		}
		return root;
	}
};