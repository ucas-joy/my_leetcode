/*
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all
the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose 
of space complexity analysis.)

Subscribe to see which companies asked this question
*/
//从前往后遍历，数组a[]每个数当前的位置保存前面数的乘积。 
//从后往前遍历，数组b[]每个数当前的位置保存这个数后面数的乘积。
// 数组a 和数组b 对应数相乘就是 所要求的结果
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int>res(nums.size(), 1);
		for (int i = 1; i < nums.size(); ++i) {
			res[i] = res[i - 1] * nums[i - 1];
		}
		int right = 1;
		for (int i = nums.size() - 1; i >= 0; i--) {
			res[i] *= right;
			right *= nums[i];
		}
		return res;
	}
};
int main238()
{
	int a[4] = { 1,2,3,4 };
	vector<int>b(a, a + 4);
	vector<int>tmp;
	Solution sol;
	tmp = sol.productExceptSelf(b);

	for (int i = 0; i < tmp.size(); ++i) {
		cout << tmp[i] << endl;
	}

}