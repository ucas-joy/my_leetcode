/*
A peak element is an element that is greater than its neighbors.

Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.

The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

You may imagine that num[-1] = num[n] = -¡Þ.

For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	/*int findPeakElement(vector<int>& nums) {
		int len = nums.size();
		if (len == 0 || len == 1)
			return 0;
		int tmp = nums[0];
		int j = 0;
		for (int i = 1; i < len; ++i) {
			if (tmp < nums[i]) {
				tmp = nums[i];
				j = i;
			}
		}
		return j;
	}*/
	int findPeakElement(const vector<int> &num) {
		int left = 0, right = num.size() - 1;
		while (left <= right) {
			if (left == right)
				return left;
			int mid = (left + right) / 2;
			if (num[mid]<num[mid + 1])
				left = mid + 1;
			else
				right = mid;
		}
		return right;
	}
};
int main()
{
	int a[5] = { 1,5,3,4,2 };
	vector<int>b(a, a + 5);
	Solution sol;
	int i = sol.findPeakElement(b);
	cout << i << endl;
	return 0;
}