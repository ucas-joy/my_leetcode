/*
Tree Depth-first Search
Show Similar Problems

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		if (nums.size() == 0)
			return NULL;
		int begin = 0;
		return build(0, nums.size() - 1, nums);
	}
	TreeNode* build( int begin , int end, vector<int>&nums){
		if (begin == end && end != nums.size() - 1) return NULL;
		int mid = (begin + end) / 2;
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = begin == mid ? NULL : build(begin, mid,nums);
		root->right = end == mid ? NULL : build(mid+1, end, nums);
		return root;
	}
};
/*
TreeNode* sortedArrayToBST(vector<int>& nums) {
	if (nums.empty()) return NULL;
	return array2bst(nums, 0, nums.size() - 1);
}
TreeNode* array2bst(vector<int>& nums, int start, int end) {
	if (start == end && end != nums.size() - 1) return NULL;
	int i = (start + end) / 2;
	TreeNode* n = new TreeNode(nums.at(i));
	n->left = start == i ? NULL : array2bst(nums, start, i);
	n->right = end == i ? NULL : array2bst(nums, i + 1, end);
	return n;
}
*/