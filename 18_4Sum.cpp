/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
[-1,  0, 0, 1],
[-2, -1, 1, 2],
[-2,  0, 0, 2]
]
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
using namespace std;
/*
class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		set<vector<int>> result;
		vector<vector<int>>rst;
		vector<int>tmp;
		if (nums.size() < 4) return rst;
		sort(nums.begin(), nums.end());
		unordered_map<int, vector<pair<int, int>>>mp;
		for (int a = 0; a < nums.size(); ++a) {
			for (int b = a + 1; b < nums.size(); ++b) {
				mp[nums[a] + nums[b]].push_back(pair<int,int>(a,b));
			}
		}
		for (int c = 0; c < nums.size(); ++c) {
			for (int d = c+1; d < nums.size(); ++d) {
				int key = target - nums[c] - nums[d];
				if (mp.find(key) == mp.end())
					continue;
				const auto&vec = mp[key];
				for (size_t k = 0; k < nums.size(); ++k){
					if ((c != vec[k].first && d != vec[k].second) || (c != vec[k].second && d != vec[k].first))
					{
						tmp.push_back(nums[vec[k].first]);
						tmp.push_back(nums[vec[k].second]);
						tmp.push_back(nums[c]);
						tmp.push_back(nums[d]);
						sort(tmp.begin(), tmp.end());
						result.insert(tmp);
						tmp.clear();
					}
				}
		    }
		 }
		rst.assign(result.begin(), result.end());
		return rst;
	}
};
*/
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > ret;
		if (num.size() == 0) return ret;
		sort(num.begin(), num.end());
		for (size_t a = 0; a < num.size(); ++a) {
			if (a != 0 && num[a] == num[a - 1]) {
				continue;
			}
			for (size_t b = a + 1; b < num.size(); ++b) {
				if (b != a + 1 && num[b] == num[b - 1]) {
					continue;
				}
				size_t c = b + 1;
				size_t d = num.size() - 1;
				while (c < d) {
					const int sum = num[a] + num[b] + num[c] + num[d];
					if (sum > target) {
						--d;
					}
					else if (sum < target) {
						++c;
					}
					else if (c != b + 1 && num[c] == num[c - 1]) {
						++c;
					}
					else if (d != num.size() - 1 && num[d] == num[d + 1]) {
						--d;
					}
					else {
						vector<int> result;

						result.push_back(num[a]);
						result.push_back(num[b]);
						result.push_back(num[c]);
						result.push_back(num[d]);
						ret.push_back(result);
						++c;
						--d;
					}
				}
			}
		}

		return ret;
	}
};


//  ³¬Ê±
//class Solution {
//public:
//	vector<vector<int> > fourSum(vector<int> &num, int target) {
//		vector<vector<int> > result;
//		set<vector<int> > res;
//		if (num.size() < 4) return result;
//		for (size_t a = 0; a < num.size(); ++a){
//			for (size_t b = 0; b < num.size(); ++b){
//				int c = b + 1;
//				int d = num.size() - 1;
//				while (c < d){
//					int sum = num[a] + num[b] + num[c] + num[d];
//					if (sum < target){
//						++c;
//					}
//					else if (sum > target){
//						--d;
//					}
//					else{
//						vector<int>tmp;
//						tmp.push_back(num[a]);
//						tmp.push_back(num[b]);
//						tmp.push_back(num[c]);
//						tmp.push_back(num[d]);
//						sort(tmp.begin(), tmp.end());
//						res.insert(tmp);
//					}
//				}
//			}
//		}
//		result.assign(res.begin(), res.end());
//		return result;
//	}
//};
//
