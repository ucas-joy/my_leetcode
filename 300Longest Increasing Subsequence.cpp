/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination,
it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1)
			return len;
		vector<int>dp(len + 1,0);
		vector<int>Tend(len + 1, 0);
		dp[0] = 1;
		Tend[0] = nums[0];
		int pre = INT_MIN;
		for (int i = 1; i < len; ++i)
		{
			if (nums[i] <= Tend[i - 1]){
				if (nums[i] > pre){
					Tend[i] = nums[i];
					dp[i] = dp[i - 1];
				}
				else
				{
					dp[i] = dp[i - 1];
					Tend[i] = Tend[i - 1];
				}
				
			}else if(nums[i]>Tend[i-1])
			{
				dp[i] = dp[i - 1] + 1;
				pre = Tend[i - 1];
				Tend[i] = nums[i];
			}
		}
		return dp[len - 1];
	}
};
*/
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1)
			return len;
		vector<int>dp(len, 0);
		dp[0] = 1;
		int maxlen = 1;
		for (int i = 0; i < len; ++i)
		{
			dp[i] = 1;
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] > nums[j])
				{
					dp[i] = max(dp[i], dp[j] + 1);
					maxlen = max(maxlen, dp[i]);
				}
			}
		}
		return maxlen;
	}
};
int main()
{
	//vector<int> a = { 10, 9, 2, 5, 3, 7, 101, 18 };
	//vector<int> a = { 2,2 };
	vector<int> a = { 1,3,6,7,9,4,10,5,6 };
	//vector<int> a = { 3,5,6,2,5,4,19,5,6,7,12 };
	Solution sol;
	int t = sol.lengthOfLIS(a);
	cout << t << endl;
	return 0;
}