/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
[-1, 0, 1],
[-1, -1, 2]
]
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		if (nums.size() < 3)
			return result;
		sort(nums.begin(), nums.end());
		int len = nums.size();
		for (int i = 0; i < len; ++i) {
			if(i != 0 && nums[i] == nums[i-1]){
				continue;
			}
			int start =i+1;
			int end = nums.size() - 1;
			while (start < end){
				if (start != i+1 && nums[start] == nums[start - 1]){
					start++;
					continue;
				}
				if (end != nums.size() - 1 && nums[end] == nums[end + 1]){
					end--;
					continue;
				}
				if (nums[start] + nums[end] + nums[i] > 0){
					end--;
				}
				else if (nums[start] + nums[end] + nums[i] < 0){
					start++;
				}
				else{
					vector<int> tmp;
					tmp.push_back(nums[i]);
					tmp.push_back(nums[start]);
					tmp.push_back(nums[end]);
					result.push_back(tmp);
					start++;
					end--;
				}			 
			}
			
		}
		return result;
	}
};

int main15()
{
	int a[6] = { -1, 0, 1, 2, -1, -4 };
	vector<int>b(a, a + 6);
	vector<vector<int>>result;
	Solution sol;
	result = sol.threeSum(b);
	cout << result.size();
	return 0;
}