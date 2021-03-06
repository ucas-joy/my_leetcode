/*
Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, 
so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>>res;
		if (words.empty())
			return res;
		unordered_map<string, int>m;
		set<int>s;
		for (int i = 0; i < words.size(); ++i){
			m[words[i]] = i;
			s.insert(words[i].size());
		}
		for (int i = 0; i < words.size(); ++i) {
			string t = words[i];
			int len = t.size();
			reverse(t.begin(), t.end());
			if (m.count(t) && m[t] != i){
				res.push_back({ i,m[t] });
			}
			auto a = s.find(len);
			for (auto it = s.begin(); it != a; ++it)
			{
				int d = *it;
				if (isPalindrome(t, 0, len - d - 1) && m.count(t.substr(len - d))) {
					res.push_back({ i,m[t.substr(len - d)] });
				}
				if (isPalindrome(t, d, len - 1) && m.count(t.substr(0, d)))
				{
					res.push_back({ m[t.substr(0,d)],i });
				}
			}
		}
		return res;
	}
	bool isPalindrome(string&t, int left, int right) {
		while (left < right) {
			if (t[left++] != t[right--]) return false;
		}
		return true;
	}
};
int main336()
{
	vector<string> s = { "tab","bat","cat" };
	Solution sol;
	vector<vector<int>> t = sol.palindromePairs(s);
	return 0;
}