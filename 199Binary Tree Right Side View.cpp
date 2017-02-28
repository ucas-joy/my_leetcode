/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
*/
#include<algorithm>
#include<stack>
#include<string>
#include<queue>
#include<vector>
// 根右左。
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//思路：层次遍历法。遍历到每层最后一个节点时，把其放到结果集中。
class Solution {
public:
	vector<int> rightSideView(TreeNode * root){
		queue<TreeNode*>tmp;
		vector<int>res;
		if (root == NULL)
			return res;
		tmp.push(root);
		while (!tmp.empty()){
			int val = tmp.back()->val;
			res.push_back(val);
			int size = tmp.size();
			for (int i = 0; i < size; ++i){
				TreeNode *tmp_node = tmp.front();
				tmp.pop();
				if (tmp_node->left != NULL){
					tmp.push(tmp_node->left);
				}
				if (tmp_node->right != NULL)
				{
					tmp.push(tmp_node->right);
				}
			}
		}
		return res;
	}

	
		
		/*vector<int>res;
		if (root == NULL)
			return res;
		TreeNode*p = root;
		root_right_left(res, p);
		return res;
	}
	void root_right_left(vector<int>&res, TreeNode *root)
	{
		if (root == NULL);
		{
			return;
		}
		res.push_back(root->val);
		if (root->left == NULL && root->right == NULL)
		{
			return;
		}
		root_right_left(res, root->right);
		root_right_left(res, root->left);
	}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
int main199()
{
	int a[6] = { 1,2,3,4,5,6 };
	int b[6] = { 3,2,4,1,6,5};
	vector<int>pre(a, a + 6);
	vector<int>in(b, b + 6);
	Solution sol;
	TreeNode *root = sol.buildTree(pre, in);
	vector<int>res = sol.rightSideView(root);

	return 0;
}