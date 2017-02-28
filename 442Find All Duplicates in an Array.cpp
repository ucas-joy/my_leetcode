/*
Given an array of integers, 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		int n = nums.size();
		int i = 0;
		while (i < n)
		{
			if (nums[i] >= 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
			{
				swap(nums[i], nums[nums[i] - 1]);
			}
			else{
				i++;
			}
		}
		vector<int> res;
		for ( i = 0; i < n; ++i)
		{
			if (nums[i] != i + 1 && nums[nums[i]-1] == nums[i])
			{
				res.push_back(nums[i]);
			}
		}
		return res;
	}
};
int main()
{
	vector<int> a = { 4,3,2,7,8,2,3,1 };
	Solution sol;
	vector<int> res = sol.findDuplicates(a);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}