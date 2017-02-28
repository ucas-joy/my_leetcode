/*
Given a non-empty array containing only positive integers, find if the array can be partitioned into
two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
/*
class Solution {
public:
	bool canPartition(vector<int>& nums) {
		if (nums.size() == 0)
			return false;
		int sum = 0;
		sum  = accumulate(nums.begin(), nums.end(), sum);
		cout << "sum = " <<sum <<  endl;
		if (sum % 2 == 1){
			return false;
		}
		sum = sum / 2;
		int n = nums.size();
		vector<vector<int>>dp(n, vector<int>(sum + 1, 0));
		for (int i = nums[0]; i <= sum; ++i){
			dp[0][i] = nums[0];
		}
		for (int i = 1; i < n; ++i){
				for (int j = nums[i]; j <= sum; ++j){
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
			}
		}
		if (dp[n - 1][sum] == sum)
			return true;
		else
			return false;
		
	}
};*/

class Solution {
public:
	bool canPartition(vector<int>& nums) {
		if (nums.size() == 0)
			return false;
		int sum = 0;
		sum = accumulate(nums.begin(), nums.end(), sum);
		if (sum % 2 == 1) {
			return false;
		}
		sum = sum / 2;
		int n = nums.size();
		vector<int>dp(sum + 1, 0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = sum; j >= 1; --j)
			{
				if (j >= nums[i])
				{
					dp[j] = max(dp[j], nums[i] + dp[j - nums[i]]);
				}
			}
		}
		return dp[sum] == sum;
	}
};
int main()
{
	vector<int> a = { 1,5,11,5 };
	Solution sol;
	bool is = sol.canPartition(a);
	cout << is << endl;
	return 0;
}