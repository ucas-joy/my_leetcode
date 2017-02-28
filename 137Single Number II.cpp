/*
Given an array of integers, every element appears three times except for one. Find that single one.
*/
#include<iostream>
#include<vector>
using namespace  std;
class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int len = nums.size();
		int result = 0;
		for (int i = 0; i < 32; ++i) {
			int count = 0;
			int mask = 1 << i;
			for (int j = 0; j < len; ++j) {
				if (nums[j] & mask)
					count++;
			}
			if (count % 3)
				result |= mask;
		}
		return result;
	}
	/*
	int singleNumber(vector<int>& nums) {
		int res = 0;
		for (int i = 0; i < 32; ++i) {
			int sum = 0;
			for (int j = 0; j < nums.size(); ++j) {
				sum += (nums[j] >> i) & 1;
			}
			res |= (sum % 3) << i;
		}
		return res;
	}
	*/
};
int main137()
{
	int a[10] = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
	vector<int>tmp(a, a + 10);
	Solution sol;
	int i = sol.singleNumber(tmp);
	cout << i << endl;
	return 0;
}