/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
Subscribe to see which companies asked this question
*/
/*
假设我们要找的第k小的数，我们令i=k/2，j=k/2，则每一次我们可以找到一定比第k个数字小的k/2个数字。

我们将这k/2个数字从数列中去掉，则我们需要寻找的第k小的数字也就变成了我们需要寻找第k-k/2小的数字。

不断重复这一个步骤，将k不断地平分，则最后会变成k=1的情况。

此时A,B两个序列中最小的一个数也就是我们要寻找的数。
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*class Solution {
public:
	int myMin(int x, int y){
		return x < y ? x : y;
	}
	int findNumber(vector<int>&nums1, vector<int>&nums2, int findKth)
	{
		int length_1 = (int)nums1.size();
		int length_2 = (int)nums2.size();
		if (length_1 == 0) return nums2[findKth - 1];
		if (length_2 == 0) return nums1[findKth - 1];

		int left_1 = 0, left_2 = 0;
		int mid_1 = 0, mid_2 = 0;
		int k;
		do {
			if (length_1 - left_1 == 0) { // 到了第一个数组的末尾
				return nums2[findKth - 1];
			}
			if (length_2 - left_2 == 0) { // left_2 到了第二个数组的末尾
				return nums1[findKth - 1];
			}
			if (findKth == 1){            // 之前排除掉的就是整个数组长 的一半的数
				return myMin(nums1[left_1], nums2[left_2]);
			}
			k = findKth / 2;
			if (length_2 - left_2 >= length_1 - left_1) { // 数组二更长
				if (length_1 - left_1 < k){
					k = length_1 - left_1;
				}
				mid_1 = left_1 + (k - 1);
				mid_2 = left_2 + (findKth - k - 1);
			}
			else {
				if (length_2 - left_2 < k){
					k = length_2 - left_2;
				}
				mid_2 = left_2 + (k - 1);
				mid_1 = left_1 + (findKth - k - 1);
			}
			if (nums1[mid_1] < nums2[mid_2]) {
				findKth -= mid_1 - left_1 + 1;
				left_1 = mid_1 + 1;
			}
			else{
				findKth -= mid_2 - left_2 + 1;
				left_2 = mid_2 + 1;
			}
		} while (true);
	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int totNumber = (int)nums1.size() + (int)nums2.size();
		int findKth = totNumber / 2;
		if (totNumber % 2 == 1) return findNumber(nums1, nums2, findKth + 1);
		else return (findNumber(nums1, nums2, findKth) + findNumber(nums1, nums2, findKth + 1)) / 2.0;
	}
};
*/
class Solution {
public:
	int myMin(int x, int y) {
		return x < y ? x : y;
	}
	int findNumber(vector<int>&nums1, vector<int>&nums2, int findKth)
	{
		int length_1 = (int)nums1.size();
		int length_2 = (int)nums2.size();
		if (length_1 == 0) return nums2[findKth - 1];
		if (length_2 == 0) return nums1[findKth - 1];

		int left_1 = 0, left_2 = 0;
		int mid_1 = 0, mid_2 = 0;
		int k;
		do {
			if (length_1 - left_1 == 0) return nums2[left_2 + findKth - 1];
			if (length_2 - left_2 == 0) return nums1[left_1 + findKth - 1];
			if (findKth == 1) return myMin(nums1[left_1], nums2[left_2]);
			k = findKth / 2;
			if (length_1 - left_1<k)
				mid_1 = length_1 - 1;
			else
				mid_1 = left_1 + k - 1;
			if (length_2 - left_2<k)
				mid_2 = length_2 - 1;
			else
				mid_2 = left_2 + k - 1;

			if (nums1[mid_1] < nums2[mid_2]) {
				findKth -= mid_1 - left_1 + 1;
				left_1 = mid_1 + 1;
			}
			else {
				findKth -= mid_2 - left_2 + 1;
				left_2 = mid_2 + 1;
			}
		} while (true);

	}
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int totNumber = (int)nums1.size() + (int)nums2.size();
		int findKth = totNumber / 2;
		if (totNumber % 2 == 1) return findNumber(nums1, nums2, findKth + 1);
		else return (findNumber(nums1, nums2, findKth) + findNumber(nums1, nums2, findKth + 1)) / 2.0;
	}
};
int main4()
{
	vector<int> a = { 1,2,3,4,5 };
	vector<int>b = { 6,7,8,9 };
	Solution sol;
	int t = sol.findMedianSortedArrays(a, b);
	cout << t << endl;
	return 0;
}