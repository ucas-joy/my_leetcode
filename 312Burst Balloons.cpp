/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. 
You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. 
Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ¡Ü n ¡Ü 500, 0 ¡Ü nums[i] ¡Ü 100

Example:

Given [3, 1, 5, 8]

Return 167

nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int size = nums.size();
		vector<vector<int>>dp(size + 1, vector<int>(size + 1, 0));
		for (int len = 1; len <= size; ++len) {
			for (int i = 0; i < size; ++i){
				int j = i + len - 1;
				for (int k = i; k <= j && j < size; ++k){
					int leftvalue = 1;
					int rightvalue = 1;
					if (i != 0){
						leftvalue = nums[i - 1];
					}
					if (j != size - 1){
						rightvalue = nums[j + 1];
					}
					int before = 0;
					int after = 0;
					if (i != k){
						before = dp[i][k - 1];
					}
					if (j != k){
						after = dp[k + 1][j];
					}
					dp[i][j] = max(leftvalue * nums[k] * rightvalue + before + after, dp[i][j]);
				}
			}
		}
		return dp[0][size - 1];
	}
};
int main312()
{
	vector<int>nums = { 3,1,5,8 };
	Solution sol;
	int t = sol.maxCoins(nums);
	cout << t << endl;
	return 0;
}