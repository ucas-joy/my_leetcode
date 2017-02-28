/*
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
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
class BSTIterator {
public:
	void inorder(TreeNode*root, vector<TreeNode*>&Inorder){
		if (root == NULL)
			return;
		inorder(root->left, Inorder);
		Inorder.push_back(root);
		inorder(root->right, Inorder);
	}
	BSTIterator(TreeNode *root) {
		inorder(root, Inorder);
		cur = 0;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return cur < Inorder.size();
	}

	/** @return the next smallest number */
	int next() {
		cur++;
		return Inorder[cur-1]->val;
	}
private:
	vector<TreeNode*>Inorder;
	int cur;
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/
