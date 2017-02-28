/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/

#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
	vector<int> intersection1(vector<int>& nums1, vector<int>& nums2) {
		vector<int>itc;
		if (nums1.size() == 0 || nums2.size() == 0) {
			return itc;
		}
		set<int>s1;
		set<int>s2;
		set<int>::iterator it;
		for (int i = 0; i < nums1.size(); ++i) {
			s1.insert(nums1[i]);
		}
		for (int i = 0; i < nums2.size(); ++i) {
			it = s1.find(nums2[i]);
			if(it != s1.end()){
				s2.insert(nums2[i]);
			}
		}
		for (it = s2.begin(); it != s2.end(); ++it) {
			itc.push_back(*it);
		}
		return itc;
	}
};

int main54()
{
	vector<int> vec1 = { 1,2,2,1 };
	vector<int> vec2 = { 2,2 };
	Solution sol;
	vector<int> s;
	s = sol.intersection1(vec1, vec2);
	for (int i = 0; i < s.size(); ++i) {
		cout << s[i] << endl;
	}
	return 0;
}

/*
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
*/