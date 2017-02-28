/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

#include<iostream>
#include<vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		if (head == NULL)
			return NULL;
		vector<int>nums;
		while (head){
			nums.push_back(head->val);
			head = head == NULL ? NULL : head->next;
		}
		return build(0, nums.size() - 1, nums);
	}
	TreeNode * build(int begin, int end, vector<int>&nums)
	{
		if (begin == end && end != nums.size() - 1) return NULL;
		int mid = (begin + end) / 2;
		TreeNode *root = new TreeNode(nums[mid]);
		root->left = begin == mid ? NULL : build(begin, mid, nums);
		root->right = end == mid ? NULL : build(mid + 1, end, nums);
		return root;
	}
};