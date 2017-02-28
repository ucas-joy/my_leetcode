/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
     1
    /  \
   2    3
  / \    \
 4   5    7
After calling your function, the tree should look like:
	1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL
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
	void connect(TreeLinkNode *root) {
		if (root == NULL)
			return;
		queue<TreeLinkNode*>q;
		TreeLinkNode *p = root;
		q.push(p);
		while (!q.empty()) {
			TreeLinkNode *tmp_node = q.front();
			int size = q.size();
			q.pop();
			if (q.empty()) {
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
			for (int i = 0; i < size - 1; ++i) {
				TreeLinkNode *tmp_next = q.front();
				q.pop();
				if (tmp_next->left != NULL) {
					q.push(tmp_next->left);
				}
				if (tmp_next->right != NULL) {
					q.push(tmp_next->right);
				}
				tmp_node->next = tmp_next;
				tmp_node = tmp_next;
			}
			tmp_node->next = NULL;
		}
		return;
	}
};