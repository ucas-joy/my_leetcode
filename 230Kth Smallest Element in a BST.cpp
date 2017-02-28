/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? 
How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).
Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

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
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode*>st;
		TreeNode *p = root;
		int tmp = 0;
		int value;
		while (p || !st.empty()){
			if (p){
				st.push(p);
				p = p->left;
			}
			else{
				p = st.top();
				tmp++;
				if (tmp == k){
					value = p->val;
					break;
				}
				st.pop();
				p = p->right;
			}
		}
		return value;
	}
};