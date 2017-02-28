/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int Max = nums[0];
		int Min = nums[0];
		int res = nums[0];
		int maxEnd = 0;
		int minEnd = 0;
		for (int i = 1; i < nums.size(); ++i){
			maxEnd = Max * nums[i];
			minEnd = Min *nums[i];
			Max = max(max(maxEnd, minEnd), nums[i]);
			Min = min(min(maxEnd, minEnd), nums[i]);
			res = max(res, Max);
		}
		return res;
	}
};
int main()
{
	vector<int> a = { 0,2 };
	Solution sol;
	int t = sol.maxProduct(a);
	cout << t << endl;
	return 0;
}