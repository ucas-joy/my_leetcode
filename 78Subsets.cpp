/*Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

	For example,
	If nums = [1, 2, 3], a solution is :

[
	[3],
	[1],
	[2],
	[1, 2, 3],
	[1, 3],
	[2, 3],
	[1, 2],
	[]
]
Subscribe to see which companies asked this question*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>>result;
		vector<int>sub1;
		result.push_back(sub1);
		if (nums.size() == 0)
		{
			return result;
		}
		int i, j, k;
		int num = 1 << nums.size();
		for (i = 0; i < num; ++i){
			vector<int>sub;
			k = 0;
			j = i;
			while (j){
				if (j & 1){
					sub.push_back(nums[k]);
				}
				j >>= 1;
				k++;
			}
			result.push_back(sub);
		}
		return result;
	}
};