/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8,
A solution set is:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
Subscribe to see which companies asked this question

Hide Tags Array Backtracking
Show Similar Problems

*/


#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int>>result;
		vector<int>path;
		set<vector<int>>result_tmp;
		sort(candidates.begin(), candidates.end());
		helper2(candidates, 0, 0, target, path, result_tmp);
		result.assign(result_tmp.begin(), result_tmp.end());
		return result;
	}
	void helper2(vector<int>&nums, int pos, int base, int target, vector<int>&path, set<vector<int>>&result){
		if (base == target){
			result.insert(path);
			return;
		}
		if (base > target){
			return;
		}
		for (int i = pos; i < nums.size(); ++i){
			path.push_back(nums[i]);
			helper2(nums, i + 1, base + nums[i], target,path, result);
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
int main40()
{
	int a[7] = { 10, 1, 2, 7, 6, 1, 5 };
	vector<int>b(a, a + 7);
	Solution sol;
	vector<vector<int>>result;
	result = sol.combinationSum2(b, 8);
	vector<vector<int>>::iterator it;
	vector<int> tmp;
	vector<int>::iterator it1;
	for (it = result.begin(); it != result.end(); ++it)
	{
		tmp = *it;
		for (it1 = tmp.begin(); it1 != tmp.end(); ++it1)
		{
			cout << *it1 << " ";
		}
		cout << endl;
	}
	return 0;
}
