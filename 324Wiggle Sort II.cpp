/*
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		int n = nums.size();

		auto midptr = nums.begin() + n / 2;
		nth_element(nums.begin(), midptr, nums.end());
		int mid = *midptr;
		int i = 1, j = 0, k = mid + 1;
		
		#define A(i) nums[(1+2*(i)) % (n|1)]

		
		while (j <= k) {
		if (A(j) > mid)
		swap(A(i++), A(j++));
		else if (A(j) < mid)
		swap(A(j), A(k--));
		else
		j++;
		}
		
	}
};
//class Solution {
//public:
//	void wiggleSort(vector<int>& nums) {
//		vector<int> tmp = nums;
//		int n = nums.size(), k = (n + 1) / 2, j = n;
//		sort(tmp.begin(), tmp.end());
//		for (int i = 0; i < n; ++i) {
//			nums[i] = i & 1 ? tmp[--j] : tmp[--k];
//		}
//	}
//};
int main()
{
	int a[6] = { 1, 3, 2, 2, 3, 1 };
	vector<int>b(a, a + 6);
	Solution sol;
	sol.wiggleSort(b);
	for (int i = 0; i < 6; ++i)
	{
		cout << b[i] << endl;
	}
	return 0;
}