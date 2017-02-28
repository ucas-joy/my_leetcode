/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int findMin(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		if (len == 1)
			return nums[0];
		if (len == 2)
			return min(nums[0], nums[1]);
		int begin = 0;
		int end = len - 1;
		while (begin < end)
		{
			while( end >= begin &&nums[begin] == nums[end]){
				end--;
			}
			if (end == begin){
				return nums[end];
			}
			if (nums[begin] < nums[end]){
				return nums[begin];
			}
			int mid = begin + (end - begin) / 2;
			if (nums[mid] == nums[end])
			{
				while (end >= begin && nums[mid] == nums[end])
				{
					end--;
				}
				if (nums[end] > nums[mid])
				{
					begin = mid + 1;
				}
			}else if (nums[mid] >= nums[end]){
				begin = mid + 1;
			}else{
				end = mid;
			}
		}
		return nums[begin];
	}
};
int main()
{
	//vector<int> a = { 4,5,6,7,0,1,2 };
	vector<int> a = { 2,0,1,1,1 };
	Solution sol;
	int t = sol.findMin(a);
	cout << t << endl;
	return 0;
}