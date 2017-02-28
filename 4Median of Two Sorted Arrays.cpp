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
��������Ҫ�ҵĵ�kС������������i=k/2��j=k/2����ÿһ�����ǿ����ҵ�һ���ȵ�k������С��k/2�����֡�

���ǽ���k/2�����ִ�������ȥ������������ҪѰ�ҵĵ�kС������Ҳ�ͱ����������ҪѰ�ҵ�k-k/2С�����֡�

�����ظ���һ�����裬��k���ϵ�ƽ�֣���������k=1�������

��ʱA,B������������С��һ����Ҳ��������ҪѰ�ҵ�����
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
			if (length_1 - left_1 == 0) { // ���˵�һ�������ĩβ
				return nums2[findKth - 1];
			}
			if (length_2 - left_2 == 0) { // left_2 ���˵ڶ��������ĩβ
				return nums1[findKth - 1];
			}
			if (findKth == 1){            // ֮ǰ�ų����ľ����������鳤 ��һ�����
				return myMin(nums1[left_1], nums2[left_2]);
			}
			k = findKth / 2;
			if (length_2 - left_2 >= length_1 - left_1) { // ���������
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