/*
Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of 
length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved.
Return an array of the k digits. You should try to optimize your time and space complexity.

Example 1:
nums1 = [3, 4, 6, 5]
nums2 = [9, 1, 2, 5, 8, 3]
k = 5
return [9, 8, 6, 5, 3]

Example 2:
nums1 = [6, 7]
nums2 = [6, 0, 4]
k = 5
return [6, 7, 6, 0, 4]

Example 3:
nums1 = [3, 9]
nums2 = [8, 9]
k = 3
return [9, 8, 9]

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:

	// 贪心求数组中的最大子数组 
	vector<int> findMaxKValue(vector<int> &nums, int k)
	{
		vector<int> result;
		if (k == 0)
			return result;
		result = vector<int>(k, 0);
		int j = 0;
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			// 出栈操作 
			while (j > 0 && n - i + j > k && nums[i] > result[j - 1])
				j--;
			// 入栈操作 
			if (j < k)
				result[j++] = nums[i];
		}
		return result;
	}
	// merge操作中的对比函数 
	bool compare(vector<int> &result1, int i, vector<int> &result2, int j)
	{
		while (i < result1.size() && j < result2.size() && result1[i] == result2[j])
		{
			i++;
			j++;
		}
		return j == result2.size() || (i < result1.size() && result1[i] > result2[j]);
	}
	// 两个数组的merge操作 
	vector<int> merge(vector<int> &nums1, vector<int> &nums2)
	{
		int m = nums1.size();
		int n = nums2.size();
		if (!m)
			return nums2;
		if (!n)
			return nums1;
		vector<int> result(m + n, 0);
		int i = 0;
		int j = 0;
		int k = 0;
		// 数组合并操作 
		while (i < m || j < n)
		{
			result[k++] = compare(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
		}
		return result;
	}
	// 返回两个数组中最大的k个数，并保持每个数组中的元素相对位置不变 
	vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
	{
		int m = nums1.size();
		int n = nums2.size();
		vector<int> result(k, 0);
		// 从数组nums中挑选k个数，在保持元素相对顺序不变的情况下，使得选出的子数组最大化。 
		for (int i = max(0, k - n); i <= min(m, k); i++)
		{
			// 在数组nums1中挑选i个数 
			vector<int> result1 = findMaxKValue(nums1, i);
			// 在数组nums2中挑选k-i个数 
			vector<int> result2 = findMaxKValue(nums2, k - i);
			// 将两个挑选出的子数组进行合并 
			vector<int> temp = merge(result1, result2);
			// 比较大小，来判断是否更新数组 
			if (compare(temp, 0, result, 0))
				result = temp;
		}
		return result;
	}
};