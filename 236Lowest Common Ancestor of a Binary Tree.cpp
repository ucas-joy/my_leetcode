

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		stack<TreeNode*>ps, st,qs;
		TreeNode *t = root;
		TreeNode *r = NULL;
		bool found_p = false;
		bool found_q = false;
		while (t || !st.empty()){
			if (t){
				st.push(t);				
				t = t->left;
			}else{
				t = st.top();
				if (t->right != NULL && t->right != r){
					t = t->right;
					st.push(t);

					t = t->left;
				}else{
					
					if ((t->val == p->val)&& !found_p) {
						ps = st;
						found_p = true;
					}
					else if ((t->val == q->val)&& !found_q){
						qs = st;
						found_q = true;
					}
					st.pop();
					r = t;
					t = NULL;
				}
			}
			if (found_p && found_q)
				break;
		}
		int qs_size = qs.size();
		int ps_size = ps.size();
		TreeNode* share_parent;
		if (qs_size == ps_size){
			share_parent = cmp(p, q, ps, qs);
		}
		else if (qs_size > ps_size)
		{
			int len = qs_size - ps_size;
			while (len--){
				qs.pop();
			}
			share_parent = cmp(p, q, ps, qs);
		}
		else if (ps_size > qs_size)
		{
			int len = ps_size - qs_size;
			while (len--) {
				ps.pop();
			}
			share_parent = cmp(p, q, ps, qs);
		}
		return share_parent;
	}
	TreeNode* cmp(TreeNode* p, TreeNode*q, stack<TreeNode*>ps, stack<TreeNode*>qs)
	{
		while (!qs.empty() && !ps.empty()) {
			TreeNode *tmp1 = qs.top();
			TreeNode *tmp2 = ps.top();
			if (tmp1->val == tmp2->val) {
				return tmp1;
			}
			qs.pop();
			ps.pop();

		}
		return NULL;
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

int main236()
{
	int a[9] = { 1,2,3,4,5,6,7,8,9 };
	int b[9] = { 3,2,5,4,6,1,8,7,9 };
	vector<int>pre(a, a + 9);
	vector<int>in(b, b + 9);
	Solution sol;
	TreeNode *root = sol.buildTree(pre, in);
	TreeNode*p = new TreeNode(5);
	TreeNode *q  = new TreeNode(9);
	TreeNode *s = sol.lowestCommonAncestor(root, p, q);
	cout << s->val << endl;
	return 0;
}