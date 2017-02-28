/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int>itc;
		if (nums1.size() == 0 || nums2.size() == 0) {
			return itc;
		}
		int hash1[1024] = { 0 };
		int hash2[1024] = { 0 };
		int len1 = nums1.size();
		int len2 = nums2.size();
		for (int i = 0; i < len1; ++i) {
			hash1[nums1[i]]++;
		}
		for (int i = 0; i < len2; ++i) {
			if (hash1[nums2[i]] > 0) {
				hash1[nums2[i]]--;
				itc.push_back(nums2[i]);
			}
		}
		return itc;
	}
};
int main()
{
	vector<int> vec1 = { 1,2,2,1 };
	vector<int> vec2 = { 2,2 };
	Solution sol;
	vector<int> s;
	s = sol.intersection(vec1, vec2);
	for (int i = 0; i < s.size(); ++i) {
		cout << s[i] << endl;
	}
	return 0;
}
