/*
Note: This is an extension of House Robber.

After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. 
This time, all houses at this place are arranged in a circle.
That means the first house is the neighbor of the last one.
Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int getMoney(vector<int>&nums, int begin, int end)
	{
		int n = nums.size();
		vector<int>maxV(n, 0);
		maxV[begin] = nums[begin];
		maxV[begin + 1] = max(nums[begin], nums[begin + 1]);
		for (int i = begin + 2; i < end; ++i)
		{
			maxV[i] = max(maxV[i - 2] + nums[i], maxV[i - 1]);
		}
		return maxV[end -1 ];
	}
	int rob(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];
		if (nums.size() == 2)
			return max(nums[0], nums[1]);
		int n = nums.size();
		return max(getMoney(nums, 0, n - 1), getMoney(nums, 1, n));
	}
	
};
int main()
{
	vector<int> a = { 1,1,1,1 };
	Solution sol;
	int t = sol.rob(a);
	cout << t << endl;
	return 0;
}

/*
class Solution {
	int robHouse(const vector<int>& nums, int bgn, int end) {
		int money1 = 0, money2 = 0, money3 = 0;
		for (int i = bgn; i<end; i++) {
			money3 = max(money2, money1 + nums[i]);
			money1 = money2;
			money2 = money3;
		}
		return money3;
	}
public:
	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums[0];
		return max(robHouse(nums, 0, nums.size() - 1), robHouse(nums, 1, nums.size()));
	}
};

*/