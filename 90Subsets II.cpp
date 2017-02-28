/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]
*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		set<vector<int>>result;
		vector<vector<int>> res;
		vector<int>sub;
		res.push_back(sub);
		int len = nums.size();
		if (len == 0){
			return res;
		}
		int num = 1 << nums.size();
		int i,j,k;
		for (i = 0; i < num; ++i)
		{
			vector<int>sub1;
			j = i;
			k = 0;
			while (j){
				if (j & 1){
					sub1.push_back(nums[k]);
				}
				j >>= 1;
				++k;
			}
			result.insert(sub1);
		}
		res.assign(result.begin(), result.end());
		return res;
	}
};
int main()
{
	int nums[3] = { 1,2,2 };
	vector<int>s(nums, nums + 3);
	Solution sol;
	vector<vector<int> >s1;
	s1 = sol.subsetsWithDup(s);
	int i = 0;
	cout << s1.size() << endl;
	return 0;

}