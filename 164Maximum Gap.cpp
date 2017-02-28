/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Credits:
Special thanks to @porker2008 for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2)
			return 0;
		int len = nums.size();
		int Max = INT_MIN;
		int Min = INT_MAX;
		for (int i = 0; i < len; ++i) {
			Min = min(Min, nums[i]);
			Max = max(Max, nums[i]);
		}
		if (Min == Max){
			return 0;
		}
		vector<bool>hasNum(len + 1);
		vector<int>maxs(len + 1);
		vector<int>mins(len + 1);
		int bid = 0;
		for (int i = 0; i < len; ++i){
			bid = bucket(nums[i], len, Min, Max);
			mins[bid] = hasNum[bid] ? min(mins[bid], nums[i]) : nums[i];
			maxs[bid] = hasNum[bid] ? max(maxs[bid], nums[i]) : nums[i];
			hasNum[bid] = true;
		}
		int res = 0;
		int lastMax = 0;
		int i = 0;
		while (i <= len) {
			if (hasNum[i++]) {
				lastMax = maxs[i - 1];
				break;
			}
		}
		for (; i <= len; ++i)
		{
			if (hasNum[i]) {
				res = max(res, mins[i] - lastMax);
				lastMax = maxs[i];
			}
		}
		return res;
	}
	int bucket(long num, long len, long min, long max)
	{
		return (int)((num - min)*len / (max - min));
	}
};

int main164()
{
	vector<int> a = { 2,5,1,3,2,3,6 };
	Solution sol;
	int d = sol.maximumGap(a);
	cout << d << endl;
	return 0;
}