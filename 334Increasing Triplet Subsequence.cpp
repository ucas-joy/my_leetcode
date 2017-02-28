/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ¡Ü i < j < k ¡Ü n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.

Credits:
Special thanks to @DjangoUnchained for adding this problem and creating all test cases.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
		bool increasingTriplet(vector<int>& nums) {
			if (nums.size() <3)
				return false;
			vector<int>::iterator second, third;
			int len = nums.size();
			int idx;
			for (int i = 0; i < nums.size();){
				second = lower_bound(nums.begin() + i + 1, nums.end(),nums[i]+1);
				if (second != nums.end()) {
					idx = distance(nums.begin(), second);
					third = lower_bound(nums.begin() + idx + 1, nums.end(),nums[idx]+1 );
					if (third != nums.end()) {
						return true;
					}
					else {
						++i;
					}
				}
				else {
					++i;
				}
			}
			return false;
		
	}
	bool increasingTriplet(vector<int>& nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			while (i < n && nums[i] >= nums[i + 1]) { i++; }
			for (int j = i + 1; j < n; j++) {
				while (i < n && j < n && nums[j] <= nums[i]) { j++; }
				for (int k = j + 1; k < n; k++) {
					while (j < n && k < n && nums[k] <= nums[j]) { k++; }
					if (i < j && j < k &&  k < n) return true;
				}
			}
		}
		return false;
	}
};

int main334()
{
	//int a[5] = { 1, 2, 3, 4, 5 };
	//int a[5] = { 5, 4, 3, 2, 1 };
	//int a[6] = { 1,2,3,1,2,1 };
	int a[7] = { 5,1,5,5,2,5,4 };
	vector<int>b(a, a + 7);
	Solution sol;
	bool is = sol.increasingTriplet(b);
	cout << is << endl;
	return 0;

}