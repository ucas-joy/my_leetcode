/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
Credits:
*/

#include<map>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		map<int,vector<pair<int, int>>> mp;
		int len1 = nums1.size();
		int len2 = nums2.size();
		map<int, vector<pair<int, int>>>::iterator it;
		for (int i = 0; i < len1; ++i) {
			for (int j = 0; j < len2; ++j){
				int sum = nums1[i] + nums2[j];
				it = mp.find(sum);
				vector<pair<int, int>>tmp;
				tmp.push_back(make_pair(nums1[i], nums2[j]));
				if (it != mp.end()){
					(it->second).push_back(make_pair(nums1[i], nums2[j]));
				}
				else{
					mp.insert(make_pair(sum, tmp));
				}
			}
		}
		int num = 0;
		vector<pair<int, int>>res;
		map<int, vector<pair<int, int>>>::iterator it1;
		for (it1 = mp.begin();it1 != mp.end();++it1){
			if (num == k){
				break;
			}
			pair<int, int>tmp1;
			vector<pair<int, int>>tmp_pair;
			tmp_pair = (it1->second);
			int len = tmp_pair.size();
			for (int j = 0; j < len; ++j){
				tmp1 = (it1->second)[j];
				res.push_back(tmp1);
				num++;
				if (num == k){
					break;
				}
			}
		}
		return res;
	}
};

int main373()
{
	int a[3] = { 1, 7, 11 }, b[3] = { 2, 4, 6 };
	int k = 3;
	vector<int>nums1(a, a + 3);
	vector<int>nums2(b, b + 3);
	Solution sol;
	vector<pair<int, int>> res = sol.kSmallestPairs(nums1, nums2,k);
	cout << res.size() << endl;
	return 0;
}