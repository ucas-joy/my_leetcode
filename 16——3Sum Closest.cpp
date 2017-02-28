/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Subscribe to see which companies asked this question
*/


#include<iostream>
#include<vector>
#include<numeric>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int sum;
		if (nums.size() <= 3) {
			sum = accumulate(nums.begin(), nums.end(), 0);
			return sum;
		}
		int ret;
		bool first = true;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i){
			int j = i + 1;
			int k = nums.size() - 1;
			while (j < k){
				int sum = nums[i] + nums[j] + nums[k];
				if (first){
					ret = sum;
					first = false;
				}
				else{
					if (abs(sum - target) < abs(ret - target))
						ret = sum;
				}
				if (ret == target)
					return ret;
				if (sum > target){
					k--;
				}
				else
					j++;
			}
		}
		return ret;
	}
};

int main16()
{
	int a[4] = { 1,1,1,0};
	vector<int>b(a, a + 4);
	Solution sol;
	int i = sol.threeSumClosest(b, 100);
	cout << i << endl;
	return 0;
}