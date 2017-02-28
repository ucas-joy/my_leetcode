/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
["aa","b"],
["a","a","b"]
]
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<vector<string>> partition(string s) {
		int len = s.length();
		vector<vector<string>>res;
		if (len == 0)
			return res;
		vector<vector<int>>dp(len + 1, vector<int>(len + 1, 0));
		for (int i = 0; i<s.size(); ++i) {
			dp[i][0] = dp[i][1] = 1;
		}
		// //dp[startindex][len] indicates whether s[start]~[start+len] is palindome
		//开始填充从某个结点开始后（2 -- s.size()）个字符串是否是回文
		for (int j = 2; j <= s.size(); ++j) {
			for (int i = 0; i + j <= s.size(); ++i) {
				dp[i][j] = dp[i + 1][j - 2] && (s[i] == s[i + j - 1]);
			}
		}
		vector<string> curRes;
		dfs(s, 0, curRes, res, dp);
		return res;
	}
	void dfs(string &s, int index, vector<string>&curRes, vector<vector<string>>&res, vector<vector<int>>&dp){
		if (index == s.length()){
			res.push_back(curRes);
			return;
		}
		for (int i = 1; i + index <= s.size(); ++i) {
			if (dp[index][i])
			{
				curRes.push_back(s.substr(index, i));
				dfs(s, index + i, curRes, res, dp);
				curRes.pop_back();
			}
		}
	}
};
int main131()
{
	string a = "aab";
	Solution sol;
	vector<vector<string>> res = sol.partition(a);
	return 0;
}

/*
class Solution {
public:
	vector<vector<string>> partition(string s) {
		int len = s.length();
		vector<vector<string>>res;
		if (len == 0)
			return res;
		vector<vector<int>>dp(len + 1, vector<int>(len + 1, 0));
		for (int i = 0; i < len; ++i){
			dp[i][0] = dp[i][1] = 1;
		}
		for (int j = 2; j <= s.size(); ++j) {
			for (int i = 0; i + j <= s.size(); ++i){
				dp[i][j] = (dp[i + 1][j - 2] && s[i] == s[i + j - 1]);
			}
		}
		vector<string>curRes;
		dfs(s, 0, curRes, res, dp);
		return res;

	}
	void dfs(string &s, int index, vector<string>&curRes, vector<vector<string>>&res, vector<vector<int>>&dp){
		if (index == s.length()){
			res.push_back(curRes);
			return;
		}
		for (int i = 1; i + index <= s.length(); ++i){
			if (dp[index][i]){
				curRes.push_back(s.substr(index,i ));
				dfs(s, index + i, curRes, res, dp);
				curRes.pop_back();
			}
		}
	}
};
*/