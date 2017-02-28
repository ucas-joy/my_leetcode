
#include<iostream>
#include<vector>
#include<algorithm>
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
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*>st;
		vector<int>postorder;
		TreeNode *p = root;
		TreeNode *r = NULL;
		while (p || !st.empty())
		{
			if (p){
				st.push(p);
				p = p->left;
			}else{
				p = st.top();
				if (p->right != NULL && p->right != r){
					p = p->right;
					st.push(p);
					p = p->left;
				}
				else
				{
					st.pop();
					postorder.push_back(p->val);
					r = p;
					p = NULL;
				}
			}
		}
		return postorder;
	}
};