/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int sum = nums[0];
		int len = nums.size();
		int i;
		int tmp = nums[0];
		for (i = 1; i < len; ++i){
			if (tmp <= 0){
				tmp = 0;
			}
			tmp += nums[i];
			if (tmp > sum){
				sum = tmp;
			}
			else if (tmp < 0){
				tmp = 0;
			}
		}
		return sum;
	}
};

int main()
{
	int a[9] = { -2,1,-3,4,-1,2,1,-5,4 };
	vector<int>b(a, a + 9);
	Solution sol;
	int sum = sol.maxSubArray(b);
	cout << sum << endl;
	return 0;
}