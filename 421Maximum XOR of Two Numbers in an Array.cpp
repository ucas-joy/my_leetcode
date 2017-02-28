/*
Given a non-empty array of numbers, a0, a1, a2, ¡­ , an-1, where 0 ¡Ü ai < 231.

Find the maximum result of ai XOR aj, where 0 ¡Ü i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:

	class TreeNode {
	public:
		TreeNode* next[2];
		TreeNode() { next[0] = NULL; next[1] = NULL; };
	};

	TreeNode* buildTree(vector<int>& nums) {
		TreeNode* root = new TreeNode(), *cur;
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			int num = nums[i];
			cur = root;
			for (int j = 31; j >= 0; j--) {
				int index = ((num >> j) & 1);
				if (cur->next[index] == NULL)
					cur->next[index] = new TreeNode();
				cur = cur->next[index];

			}
		}
		return root;
	}

	int helper(TreeNode* cur, int num) {
		int res = 0;
		for (int i = 31; i >= 0; i--) {
			int index = ((num >> i) & 1) ? 0 : 1;

			if (cur->next[index]) {
				res <<= 1;
				res |= 1;
				cur = cur->next[index];
			}
			else {
				res <<= 1;
				res |= 0;
				cur = cur->next[index ? 0 : 1];
			}
		}
		return res;
	}

	int findMaximumXOR(vector<int>& nums) {
		int res = 0;
		TreeNode* root = buildTree(nums);

		for (auto i : nums) {
			res = max(res, helper(root, i));
		}

		return res;
	}
};
int main421()
{
	//int a[6] = { 3, 10, 5, 25, 2, 8 };
	//vector<int>b(a, a + 6);
	int a[3] = { 8,10,2 };
	vector<int>b(a, a + 3);
	Solution sol;
	int t = sol.findMaximumXOR(b);
	cout << t << endl;
	return 0;
}