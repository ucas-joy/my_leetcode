/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int>dp(target + 1,0);
		dp[0] = 1;
		for (int n = 0; n < target + 1; ++n){
			for (int m = 0; m < nums.size(); ++m){
				if (n >= nums[m]) dp[n] = dp[n] + dp[n - nums[m]];
			}
		}
		return dp[target];
	}
};
int main()
{
	vector<int> a = { 1,2,3 };
	int target = 4;
	Solution sol;
	int t = sol.combinationSum4(a, target);
	cout << t << endl;
	return 0;
}