/*
ind all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a
unique set of numbers.


Example 1:

Input: k = 3, n = 7

Output:

[[1,2,4]]

Example 2:

Input: k = 3, n = 9

Output:

[[1,2,6], [1,3,5], [2,3,4]]
Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<vector<int>> result;
		vector<int>path;	
		helper3(k, 1, 0, n, path, result);
		return result;
	}
	void helper3(int k , int pos , int base ,int n, vector<int>&path, vector<vector<int>>&result)
	{
		if (base == n&& path.size() == k)
		{
			sort(path.begin(), path.end());
			result.push_back(path);
			return;
		}
		if (path.size() > k || base > n)
		{
			return;
		}
		for (int i = pos; i < 10; i++)
		{
			path.push_back(i);
			helper3(k, i + 1, base + i,n, path, result);
			path.pop_back();
		}
	}
};
int main216()
{
	Solution sol;
	vector<vector<int>>result;
	result = sol.combinationSum3(3, 9);
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