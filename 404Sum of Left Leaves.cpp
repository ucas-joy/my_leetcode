/*
Find the sum of all left leaves in a given binary tree.

Example:

      3
    /  \
  9     20
	   /  \
	  15	7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.
Subscribe to see which companies asked this question
*/


#include<iostream>
using namespace std;
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL || (root->left == NULL && root->right == NULL))
			return 0;
		int res = 0;
		helper(root->left, true, res);
		helper(root->right, false, res);
		return res;
	}
	void helper(TreeNode* node, bool left, int& res) {
		if (node == NULL)
			return;
		if (left && (node->left == NULL && (node->right == NULL))) res = res + node->val;
		helper(node->left, true, res);
		helper(node->right, false, res);
	}
};
int createTree(TreeNode **root, int value)
{
	if (*root == NULL)
	{
		*root = (TreeNode *)malloc(sizeof(TreeNode));
		(*root)->val = value;
		(*root)->left = NULL;
		(*root)->right = NULL;
		return  0;
	}
	else if (value < (*root)->val)
	{
		createTree(&((*root)->left), value);
	}
	else
	{
		createTree(&((*root)->right), value);
	}

}


void inOrder(TreeNode *root)                               //这个是中序遍历，先根，左子树，右子树
{
	// cout << 1 << endl;
	if (root == NULL) {
		//             cout << "the tree is null !" <<endl;
		return ;
	}
	//             cout << 2 << endl;
	inOrder(root->left);
	cout << root->val <<" ";
	inOrder(root->right);

}
void preOrder(TreeNode *root)                               //这个是中序遍历，先根，左子树，右子树
{
	// cout << 1 << endl;
	if (root == NULL) {
		//             cout << "the tree is null !" <<endl;
		return ;
	}
	//             cout << 2 << endl;
	cout << root->val << " ";
	preOrder(root->left);
	
	preOrder(root->right);

}

int main404(int argc, char *argv[])
{
	TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
	//TreeNode BTree;
	int a[] = { 3, 5, 1, 4 , 6 ,2, 0 };
	int len = sizeof(a) / sizeof(*a);
	int i = 0;
	int j = 10;
	int value;
	root->val = a[0];
	root->left = root->right = NULL;
	for (i = 1; i < len; i++)
	{
		createTree(&root, a[i]);
	};
	cout << "中序遍历：" << endl;
	inOrder(root);
	cout << endl;
	cout << "先序遍历" << endl;
	preOrder(root);
	cout << endl;
	Solution sol;
	int t = sol.sumOfLeftLeaves(root);
	cout << t << endl;
	return 0;
}

