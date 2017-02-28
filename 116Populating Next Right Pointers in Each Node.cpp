/*
Given a binary tree

struct TreeLinkNode {
TreeLinkNode *left;
TreeLinkNode *right;
TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
   1
  /  \
 2    3
 / \  / \
4  5  6  7
After calling your function, the tree should look like:
    1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \  / \
4->5->6->7 -> NULL
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<queue>
using namespace std;
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}

};
class Solution {
public:
/*	void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;
		queue<TreeLinkNode*>q;
		TreeLinkNode *p = root;
		q.push(p);
		while (!q.empty()){	
			TreeLinkNode *tmp_node = q.front();
			int size = q.size();
			q.pop();
			if (q.empty()){
				tmp_node->next = NULL;
			}
			if (tmp_node->left != NULL)
			{
				q.push(tmp_node->left);
			}
			if (tmp_node->right != NULL)
			{
				q.push(tmp_node->right);
			}
			for (int i = 0; i < size-1; ++i){
				TreeLinkNode *tmp_next = q.front();
				q.pop();
				if (tmp_next->left != NULL){
					q.push(tmp_next->left);
				}
				if (tmp_next->right != NULL){
					q.push(tmp_next->right);
				}
				tmp_node->next = tmp_next;
				tmp_node = tmp_next;
			}
			tmp_node->next = NULL;
		}
		return;
	}*/
	void connect(TreeLinkNode *root) {
		if (root == NULL) {
			return;
		}
		rec(root);
	}
	void rec(TreeLinkNode *root)
	{
		if (root == NULL){
			return;
		}
		if (root->left != NULL){
			root->left->next = root->right;
		}
		if (root->next!= NULL && root->right != NULL){
			root->right->next = root->next->left;
		}
		rec(root->left);
		rec(root->right);
	}

};