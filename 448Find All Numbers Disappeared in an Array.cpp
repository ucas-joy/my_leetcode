/*
Given an array of integers where 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]
Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int n = nums.size();
		int i = 0;
		while (i < n){
			if (nums[i] >= 1 && nums[i] <= n && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]){
				swap(nums[i], nums[nums[i] - 1]);
			}
			else{
				i++;
			}
		}
		vector<int>res;
		for (int i = 0; i < n; ++i){
			if (nums[i] != i + 1){
				res.push_back(i + 1);
			}
		}
		return res;
	}
};
int main448()
{
	vector<int> a = { 4,3,2,7,8,2,3,1 };
	Solution sol;
	vector<int> res = sol.findDisappearedNumbers(a);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] <<" ";
	}
	cout << endl;
	return 0;
}