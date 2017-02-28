/*
Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.
Write an algorithm to minimize the largest sum among these m subarrays.

Note:
Given m satisfies the following constraint: 1 ¡Ü m ¡Ü length(nums) ¡Ü 14,000.

Examples:

Input:
nums = [7,2,5,10,8]
m = 2

Output:
18

Explanation:
There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8],
where the largest sum among the two subarrays is only 18.
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
	bool doable(const vector<int>& nums, int cuts, long long Max) {
		int acc = 0;
		for (auto num : nums) {
			// This step is unnecessary for this problem. I didn't discard this line because I want doable function more generalized.
			if (num > Max) return false;
			else if (acc + num <= Max) acc += num;
			else {
				--cuts;
				acc = num;
				if (cuts < 0) return false;
			}
		}
		return true;
	}

public:
	int splitArray(vector<int>& nums, int m) {
		long long left = 0, right = 0;
		for (auto num : nums) {
			left = max(left, (long long)num);
			right += num;
		}

		while (left < right) {
			long long mid = left + (right - left) / 2;
			if (doable(nums, m - 1, mid)) right = mid;
			else left = mid + 1;
		}
		return left;
	}
};
int main410()
{
	vector<int> nums = { 7,2,5,10,8 };
	Solution sol;
	int t = sol.splitArray(nums, 2);
	cout << t << endl;
	return 0;
}