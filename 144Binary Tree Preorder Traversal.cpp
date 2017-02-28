
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
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*>st;
		TreeNode *p = root;
		vector<int>preorder;
		while (p || !st.empty()){
			if (p){
				preorder.push_back(p->val);
				st.push(p);
				p = p->left;
			}
			else{
				p = st.top();
				st.pop();
				p = p->right;
			}
		}
		return preorder;
	}
	
};