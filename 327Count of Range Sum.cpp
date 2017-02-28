/*
Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
Range sum S(i, j) is defined as the sum of the elements in nums between indices i and j (i ¡Ü j), inclusive.

Note:
A naive algorithm of O(n2) is trivial. You MUST do better than that.

Example:
Given nums = [-2, 5, -1], lower = -2, upper = 2,
Return 3.
The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
	int countRangeSum(vector<int>& nums, int lower, int upper) {
		long long sum = 0, ret = 0;
		multiset<long long> accum = { 0 };
		for (auto x : nums) {
			sum += x;
			auto start = accum.lower_bound(sum - upper), end = accum.upper_bound(sum - lower);
			while (start != end)
			{
				ret++, start++;
			}
			accum.insert(sum);
		}
		return ret;
	}
};
int main327()
{
	vector<int> a = { -1,5,-2 ,4,6,-8,3,-4,};
	Solution sol;
	int cnt = sol.countRangeSum(a,-2,2);
	cout << cnt << endl;
	return 0;
}



/*
int countRangeSum(vector<int>& nums, int lower, int upper) {
	long long sum = 0, ret = 0;
	multiset<long long> accum = { 0 };
	for (auto x : nums) {
		sum += x;
		auto start = accum.lower_bound(sum - upper), end = accum.upper_bound(sum - lower);
		while (start != end) ret++, start++;
		accum.insert(sum);
	}
	return ret;
}
*/




/*
class Solution {
public:
	int mergeSort(vector<long>& sum, int lower, int upper, int low, int high)
	{
		if (high - low <= 1) return 0;
		int mid = (low + high) / 2, m = mid, n = mid, count = 0;
		count = mergeSort(sum, lower, upper, low, mid) + mergeSort(sum, lower, upper, mid, high);
		for (int i = low; i< mid; i++)
		{
			while (m < high && sum[m] - sum[i] < lower) m++;
			while (n < high && sum[n] - sum[i] <= upper) n++;
			count += n - m;
		}
		inplace_merge(sum.begin() + low, sum.begin() + mid, sum.begin() + high);
		return count;
	}

	int countRangeSum(vector<int>& nums, int lower, int upper) {
		int len = nums.size();
		vector<long> sum(len + 1, 0);
		for (int i = 0; i< len; i++) sum[i + 1] = sum[i] + nums[i];
		return mergeSort(sum, lower, upper, 0, len + 1);
	}
};
*/


