#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//class Solution {
//public:
//	int countNodes(TreeNode* root) {
//		if (root == NULL)
//			return 0;
//		queue<TreeNode*>pq;
//		TreeNode* p = root;
//		pq.push(p);
//		int count = 0;
//		while (!pq.empty()){
//			p = pq.front();
//			pq.pop();
//			count++;
//			if (p->left != NULL){
//				pq.push(p->left);
//			}
//			if (p->right != NULL){
//				pq.push(p->right);
//			}
//		}
//		return count;
//	}
//};
class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == NULL)
			return 0;
		int left_height = 0;
		int right_height = 0;
		TreeNode *L = root;
		TreeNode *R = root;
		while (L){
			left_height++;
			L = L->left;
		}
		while (R) {
			right_height++;
			R = R->right;
		}
		if (left_height == right_height)
			return pow(2, left_height) - 1;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};