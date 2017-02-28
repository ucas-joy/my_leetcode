/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7,
A solution set is:
[
[7],
[2, 2, 3]
]
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//class Solution {
//public:
//	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//		vector<vector<int>> result;
//		vector<int> path;
//		sort(candidates.begin(), candidates.end());
//		helper(candidates, 0, 0, target, path, result);
//		return result;
//	}
//
//	void helper(vector<int> &nums, int pos, int base, int target, vector<int>& path, vector<vector<int>> & result)
//	{
//		if (base == target)
//		{
//			result.push_back(path);
//			return;
//		}
//		if (base>target)
//			return;
//		for (int i = pos; i<nums.size(); i++)
//		{
//			path.push_back(nums[i]);
//			helper(nums, i, base + nums[i], target, path, result);
//			path.pop_back();
//		}
//	}
//};



class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>>result;
		vector<int>path;
		sort(candidates.begin(), candidates.end());
		helper(candidates, 0, 0, target, path, result);
		return result;
	}
	void helper(vector<int>&nums, int pos, int base,int target, vector<int>&path, vector<vector<int>>&result){
		if (base == target){
			result.push_back(path);
			return;
		}
		if (base > target)
			return;
		for (int i = pos; i < nums.size(); ++i){
			path.push_back(nums[i]);
			print(path);
			helper(nums, i, base+nums[i], target, path, result);
			print(path);
			path.pop_back();
		}
	}
	void print(vector<int>&nums)
	{
		int len = nums.size();
		int i = 0;
		while (i < len)
		{
			cout << nums[i] << " ";
			i++;
		}
		cout << endl;
	}
};
int main39()
{
	int a[4] = { 2, 3, 6, 7 };
	vector<int>b(a, a + 4);
	Solution sol;
	vector<vector<int>>result;
	result = sol.combinationSum(b, 7);
	vector<vector<int>>::iterator it;
	vector<int> tmp;
	vector<int>::iterator it1;
	for (it = result.begin(); it != result.end(); ++it)
	{
		tmp = *it;
		for (it1 = tmp.begin(); it1 != tmp.end(); ++it1)
		{
			cout << *it1<< " ";
		}
		cout << endl;
	}
	return 0;
}
