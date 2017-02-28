/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
Subscribe to see which companies asked this question

Hide Tags Tree Depth-first Search

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
	void recoverTree(TreeNode* root) {
		if (root == NULL)
			return;
		stack<TreeNode*>st;
		TreeNode dummy(-1);
		TreeNode *wrong1 = &dummy;
		TreeNode *wrong2 = &dummy;
		TreeNode *tmp_wrong = &dummy;
		stack<TreeNode*>tmp_st;
		bool found1 = false;
		bool found2 = false;
		bool flag = false;
		TreeNode *p = root;
		while (p || !st.empty()){
			if (p){
				st.push(p);
				p = p->left;
			}else{
				p = st.top();
				tmp_st.push(p);
				if ((!found1) && iswrong1(tmp_st)){
					stack<TreeNode*>tmp = tmp_st;
					tmp_wrong = tmp.top();
					tmp.pop();
					wrong1 = tmp.top();
					found1 = true;
					flag = true;
				}
				if (!flag && found1 && iswrong1(tmp_st)){
					stack<TreeNode*>tmp = tmp_st;
				//	tmp.pop();
					wrong2 = tmp.top();
					found2 = true;
				}
				flag = false;
				st.pop();
				p = p->right;
			}
			if (found1 && found2)
				break;
		}
		if (found1 && found2){
			swap(wrong1->val, wrong2->val);
		}
		if (found1 && !found2){
			swap(wrong1->val, tmp_wrong->val);
		}
		if (!found1 && !found2){
			wrong1 = tmp_st.top();
			tmp_st.pop();
			wrong2 = tmp_st.top();
			swap(wrong1->val, wrong2->val);
		}
		return;
	}
	bool iswrong1(stack<TreeNode*>&inorder){
		stack<TreeNode*>tmp = inorder;
		if (tmp.size() >= 2){
			TreeNode *t = tmp.top(); // 2
			tmp.pop();
			TreeNode *p = tmp.top(); // 3
			if (t->val < p->val)
				return true;
		}
		return false;
	}
///////////////////////////////////////////////////////////////////////////////////////////////½¨Ê÷¹ý³Ì
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
int main99()
{
	int a[3] = {2,3,1 };
	int b[3] = { 3,2,1};
	vector<int>pre(a, a + 3);
	vector<int>in(b, b + 3);
	Solution sol;
	TreeNode *root = sol.buildTree(pre, in);
	sol.recoverTree(root);
	return 0;
}