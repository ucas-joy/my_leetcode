/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return 0;
		int left = 0;
		int right = nums.size() - 1;
		bool found = false;
		while (left <= right){
			int mid = (left + right) / 2;
			if (nums[mid] > target){
				right = mid - 1;
			}
			else if (nums[mid] < target){
				left = mid + 1;
			}
			else{
				found = true;
				return mid;
			}
		}
		if (found == false){
			if (nums[0] > target)
				return 0;
			if (nums[nums.size() - 1] < target)
				return nums.size();
			for (int i = 0; i < nums.size() - 1; ++i){
				if (nums[i] < target && nums[i + 1]>target)
					return i + 1;
			}
		}
		return 0;
	}
};

int main()
{
	int a[2] = { 1,3 };
	vector<int>b(a, a + 2);
	Solution sol;
	int pos = sol.searchInsert( b,2);
	cout << pos << endl;
	return 0;
}