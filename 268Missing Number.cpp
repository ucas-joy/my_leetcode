/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.
*/
#include<iostream>
#include<vector>
using namespace  std;
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		
		int min = 0;
		int max = nums.size() - 1;
		int mid = min + (max - min) / 2;
		while (min < max) {
			int mid = min + (max - min) / 2;
			if (nums[mid] == mid){
				min = mid + 1;
			}
			else
			{
				max = mid - 1;
			}
		}
		return min == nums[min] ? min + 1 : min;
	}
};
int main268()
{
	int a[3] = { 0,1,3 };
	vector<int>tmp(a, a + 3);
	Solution sol;
	int i = sol.missingNumber(tmp);
	cout << i << endl;
	return 0;
}