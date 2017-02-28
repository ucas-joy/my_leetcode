/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool canJump(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1)
			return true;
		int maxjump = -1;
		int len = nums.size();
		for (int i = 0; i < len; ++i)
		{
			if (maxjump < nums[i])
				maxjump = nums[i];
			if (maxjump > len - i - 1)
				return true;
			if (maxjump == 0)
				return false;
			maxjump--;
		}
		return false;
	}
};
int main55()
{
	int A[5] = { 2, 3, 1, 1, 4 };
	vector<int>a(A,A + 5);
	Solution sol;
	bool is;
	is = sol.canJump(a);
	cout << is << endl;
	return 0;
}
		