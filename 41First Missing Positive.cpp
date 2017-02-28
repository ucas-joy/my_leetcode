/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int n = nums.size();
		int i = 0; 
		while (i < n){
			if (nums[i] >= 1 && nums[i] < n && nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]){
				swap(nums[i], nums[nums[i] - 1]);
			}
			else{
				i++;
			}
		}
		for (i = 0; i < n; ++i){
			if (nums[i] != i + 1)
				return i + 1;
		}
		return n + 1;
	}
};
int main()
{
	vector<int> a = { 2,2,2 };
	Solution sol;
	int t = sol.firstMissingPositive(a);
	cout << t << endl;
	return 0;
}