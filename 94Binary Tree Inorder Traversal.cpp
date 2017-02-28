

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
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> st;
		vector<int>inorder;
		TreeNode *p = root;
		while (p || !st.empty()){
			if (p){
				st.push(p);
				p = p->left;
			}
			else{
				p = st.top();
				inorder.push_back(p->val);
				st.pop();
				p = p->right;
			}
		}
		return inorder;
	}
};
