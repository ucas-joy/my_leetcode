/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

	5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

	 5
	/ \
   4   6
  /     \
 2       7

Another valid answer is [5,2,6,null,4,null,7].

	5
   / \
  2   6
   \   \
	4   7
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<sstream>
#include<string>
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
	
	TreeNode* deleteNode(TreeNode* root, int key) {
		TreeNode preroot(0);
		TreeNode *pre = &preroot;
		pre->right = root;
		while (root != NULL && root->val != key){
			pre = root;
			if (root->val < key)
				root = root->right;
			else
				root = root->left;
		}
		if (root != NULL && root->left != NULL) {   //*********don't need to check root != NULL if return early
			TreeNode* del = root->left;
			pre = root;
			while (del->right != NULL) {
				pre = del;
				del = del->right;
			}
			root->val = del->val;
			root = del;
		}
		TreeNode* next = root;
		if (next != NULL && next->left != NULL)  //*********don't need to check next != NULL if return early      
			next = next->left;
		else if (next != NULL)
			next = next->right;


		if (pre->left == root)
			pre->left = next;
		else
			pre->right = next;
		return preroot.right;

	}

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
int main450()
{
	int a[8] = { 5,3,2,1,4,7,6,8};
	int b[8] = { 1,2,3,4,5,6,7,8 };
	vector<int>pre(a, a + 8);
	vector<int>in(b, b + 8);
	Solution sol;
	TreeNode *root = sol.buildTree(pre, in);
	TreeNode *t = sol.deleteNode(root, 3);
	return 0;
}