/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red,
white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	void sortColors(vector<int>& nums) {
		int red = 0, blue = nums.size() - 1;
		for (int i = red; i <= blue; ++i)
		{
			if (nums[i] == 0)
				swap(nums[red++], nums[i]);
			else if (nums[i] == 2)
				swap(nums[i--], nums[blue--]);
		}
		return;
	}
};
int main75()
{
	int a[2] = { 2,1 };
	vector<int>tmp(a, a + 2);
	Solution sol;
	sol.sortColors(tmp);
	int len = tmp.size();
	int i = 0;
	while (i < len)
	{
		cout << a[i] << " ";
		i++;
	}

	return 0;
}