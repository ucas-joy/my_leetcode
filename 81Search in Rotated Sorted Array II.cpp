/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool search(vector<int>& nums, int target) {
		if (nums.size() == 0)
			return false;
		int left = 0;
		int right = nums.size() - 1;
		while (left < right){
			int mid = left + (right - left) / 2;
			if (nums[mid] == target){
				return true;
			}
			if (nums[mid] > nums[left]){
				if (nums[left] <= target && nums[mid] >= target){
					right = mid - 1;
				}
				else{
					left = mid + 1;
				}
			}
			else if(nums[mid] < nums[left]){
				if (nums[right] >=target && nums[mid] <= target){
					left = mid + 1;
				}
				else{
					right = mid - 1;
				}
			}
			else {
				left++;
			}			
		}
		return false;
	}
};
int main81()
{
	int a[7] = { 4,5,6,7,0,1,2 };
	vector<int>b(a, a + 7);
	Solution sol;
	bool found;
	found = sol.search(b, 8);
	cout << found;
	return 0;
}