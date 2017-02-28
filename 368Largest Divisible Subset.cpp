/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset 
satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]
Credits:
Special thanks to @Stomach_ache for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/


#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		vector<int>result;
		int len = nums.size();
		if (len == 0){
			return result;
		}
		sort(nums.begin(), nums.end());
		vector<int>length(nums.size() + 1, 0);
		vector<int>pre(nums.size());
		int max_len = -1;
		int head = -1;

		for (int i = 0; i < len; ++i) {
			pre[i] = -1;
			length[i] = 1;
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] % nums[j] == 0 && length[j] + 1 > length[i])
				{
					pre[i] = j;
					length[i] = length[j] + 1;
				}
				if (max_len < length[i]) {
					max_len = length[i];
					head = i;
				}
			}
			while (head != -1)
			{
				result.push_back(nums[head]);
				head = pre[head];
			}
			return result;
		}
/*
		bool found = false;
		int max_len = INT_MIN;
		int max_idx = -1;
		vector<vector<int>>dp(len + 1, vector<int>(len + 1, 0));
		vector<int>pre(len + 1, -1);
		for (int i = 0; i < len; ++i){
			dp[i][i] = 1;
		}
		for (int i = 0; i < len; ++i) {
			for (int j = i; j < len; ++j){
				int t = i;
				while (--t){
					if (nums[j] % nums[t] == 0){
						pre[j] = t;
						dp[i][j] = dp[t][j] + 1;
						if (max_len <= dp[i][j]){
							max_len = dp[i][j];
							max_idx = j;
						}
						found = true;
						break;
					}
				}
				if (!found){
					dp[i][j] = 1;
				}
			}
		}
		*/
	}
};
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<int> ptr(nums.size());
		vector<int> length(nums.size());
		vector<int> ret;
		int maxLength = -1;
		int head = -1;

		for (int i = 0; i < nums.size(); ++i) {
			ptr[i] = -1;
			length[i] = 1;
			for (int j = 0; j < i; ++j) {
				if (nums[i] % nums[j] == 0 && length[j] + 1 > length[i]) {
					ptr[i] = j;
					length[i] = length[j] + 1;
				}
			}
			if (maxLength < length[i]) {
				maxLength = length[i];
				head = i;
			}
		}

		while (head != -1) {
			ret.push_back(nums[head]);
			head = ptr[head];
		}
		return ret;
	}
};
int main()
{
	int a[5] = { 1,2,4,5,8 };
	vector<int>b(a, a +5);
	Solution sol;
	vector<int>c = sol.largestDivisibleSubset(b);
	for(int k = 0 ; k < c.size(); ++k)
	{
		cout << c[k] << " ";
	}
	return 0;
}