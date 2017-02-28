/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.
Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int len = nums.size();
		int AorB = 0;
		for (int i = 0; i < len; ++i)
		{
			AorB ^= nums[i];
		}
		int lowbit = AorB & (-AorB);
	//	int lowbit = AorB &(~(AorB - 1));
		int A = 0;
		int B = 0;
		for (int i = 0; i < len; ++i)
		{
			if ((lowbit & nums[i]) == 0)
			{
				A ^= nums[i];
			}
			else
			{
				B ^= nums[i];
			}
		}
		vector<int>res;
		res.push_back(A);
		res.push_back(B);
		return res;
	}
};
int main260()
{
	int a[6] = { 1,3,5,6,3,1 };
	vector<int>tmp(a, a + 6);
	vector<int>tmp1;
	Solution sol;
	tmp1 = sol.singleNumber(tmp);
	for (int i = 0; i < tmp1.size(); ++i)
	{
		cout << tmp1[i] << endl;
	}
	return 0;

}