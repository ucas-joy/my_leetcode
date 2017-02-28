/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the 
difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		if (nums.size() <= 1)
			return false;
		map<int, int>mp;
		int j = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i - j > k && mp[nums[j]] == j) mp.erase(nums[j++]);
			auto a = mp.lower_bound(nums[i] - t);
			if (a != mp.end() ) return true;
			mp[nums[i]] = i;
		}
		return  false;
	}
};
int main()
{
	vector<int> a = { 1,3,1 };
	
	int t = 1, k = 2;
	Solution sol;
	bool is = sol.containsNearbyAlmostDuplicate(a, k, t);
	cout << is << endl;
	return 0;
}