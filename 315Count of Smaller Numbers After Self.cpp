/*
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of
smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/
// ÇóÄæÐòÊý
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	struct TreeNode {
		int val;
		int count;
		TreeNode *left;
		TreeNode *right;
		TreeNode(int v,int c = 0, TreeNode*l =NULL,TreeNode*r = NULL) : val(v),count(c), left(l), right(r) {}
	};
	void insert(TreeNode *&root, int num, int &ret){
		if (root == NULL){
			root = new TreeNode(num);
			return;
		}
		if (num > root->val){
			ret += root->count + 1;
			insert(root->right, num, ret);
		}
		else{
			root->count++;
			insert(root->left, num, ret);
		}
	}
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> res;
		int n = nums.size();
		if (n == 0)
			return res;
		res.resize(n, 0);
		TreeNode *root = new TreeNode(nums[n-1]);
		for (int i = n-2; i >=0; --i)
		{
			insert(root, nums[i], res[i]);
		}
		return res;
	}
};
int main()
{
	vector<int>a = { 5,2,6,1 };
	Solution sol;
	vector<int> b = sol.countSmaller(a);
	for (int i = 0; i < b.size(); ++i)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;
}



/*
vector<int> countSmaller(vector<int>& nums) {
	vector<int> s;
	vector<int> ans;
	for (int i = nums.size() - 1; i >= 0; i--) {
		if (s.empty()) {
			s.push_back(nums[i]);
			ans.push_back(0);
			continue;
		}
		int l = 0, r = s.size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (s[mid] < nums[i]) {
				l = mid + 1;
			}
			else r = mid - 1;
		}
		s.insert(s.begin() + l, nums[i]);
		ans.push_back(l);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
*/