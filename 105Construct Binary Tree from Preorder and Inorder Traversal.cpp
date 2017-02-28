
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
	//int llen, rlen;
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
void PostOrder(TreeNode *root)                               //这个是中序遍历，先根，左子树，右子树
{
	// cout << 1 << endl;
	if (root == NULL) {
		//             cout << "the tree is null !" <<endl;
		return;
	}
	//             cout << 2 << endl;
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->val << " ";
}
int main105()
{
	int a[5] = { 1,2,3,4,5 };
	int b[5] = { 3,2,4,1,5 };
	vector<int>pre(a, a + 5);
	vector<int>in(b, b + 5);
	Solution sol;
	TreeNode *root = sol.buildTree(pre, in);
	cout << "PostOrder:" << endl;
	PostOrder(root);
	return 0;
}