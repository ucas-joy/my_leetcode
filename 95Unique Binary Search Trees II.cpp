/*
Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

1         3     3      2      1
 \       /     /      / \      \
  3     2     1      1   3      2
 /     /       \                 \
2     1         2                 3
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> res;
		if (n == 0){
			return res;
		}
		res =  Helper(1, n);
		return res;
	}
	vector<TreeNode*>Helper(int begin, int end){
		vector<TreeNode*>ret;
		if (begin > end){
			ret.push_back(NULL);
		}
		else if (begin == end){
			TreeNode *node = new TreeNode(begin);
			ret.push_back(node);
		}
		else{
			for (int i = begin; i <= end; ++i){
				vector<TreeNode*> left = Helper(begin, i - 1);
				vector<TreeNode*> right = Helper(i + 1, end);
				for (int l = 0; l < left.size(); ++l){
					for (int r = 0; r < right.size(); ++r){
						TreeNode *root = new TreeNode(i);
						root->left = left[l];
						root->right = right[r];
						ret.push_back(root);
					}
				}
			}
		}
		return ret;
	}
};
int main95()
{
	int n = 3;
	Solution sol;
	vector<TreeNode*>res = sol.generateTrees(n);
	return 0;
}
/*
class Solution {
public:
	vector<TreeNode *> generateTrees(int n) {
		return Helper(1, n);
	}
	vector<TreeNode *> Helper(int begin, int end)
	{
		vector<TreeNode *> ret;
		if (begin > end)
			ret.push_back(NULL);
		else if (begin == end)
		{
			TreeNode* node = new TreeNode(begin);
			ret.push_back(node);
		}
		else
		{
			for (int i = begin; i <= end; i++)
			{//root
				vector<TreeNode *> left = Helper(begin, i - 1);
				vector<TreeNode *> right = Helper(i + 1, end);
				for (int l = 0; l < left.size(); l++)
				{
					for (int r = 0; r < right.size(); r++)
					{
						//new tree
						TreeNode* root = new TreeNode(i);
						root->left = left[l];
						root->right = right[r];
						ret.push_back(root);
					}
				}
			}
		}
		return ret;
	}
};
*/