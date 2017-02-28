/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:

[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		if (strs.size() == 0)
			return res;
		map<string, vector<string>> mp;
		int i;
		for (i = 0; i < strs.size(); ++i)
		{
			string s = strs[i];
			sort(strs[i].begin(), strs[i].end());
			mp[strs[i]].push_back(s);
		}
		map<string, vector<string>>::iterator it;
		for (it = mp.begin(); it != mp.end(); ++it)
		{
			res.push_back(it->second);
		}
		return res;
	}
};

int main49()
{
	string a[6] = { "eat", "tea", "tan", "ate", "nat", "bat" };
	vector<string>s1(a, a + 6);
	Solution sol;
	vector<vector<string>> res;
	res = sol.groupAnagrams(s1);
	int i = 0, j = 0;
	for (i = 0; i < res.size(); ++i)
	{
		for (j = 0; j < res[i].size(); ++j)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}