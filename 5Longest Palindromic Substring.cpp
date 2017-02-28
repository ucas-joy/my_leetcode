/*
5. Longest Palindromic Substring   QuestionEditorial Solution  My Submissions
Total Accepted: 143746
Total Submissions: 599720
Difficulty: Medium
Contributors: Admin
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one
unique longest palindromic substring.

Subscribe to see which companies asked this question
*/
/*
Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//暴力，超时！
/*
class Solution {
public:
	bool isPalinedrome(string s) {
		bool is;
		string s1 = s;
		reverse(s1.begin(), s1.end());
		if (s1 == s) {
			is = true;
		}
		else {
			is = false;
		}
		return is;
	}
	string longestPalindrome(string s) {
		int len = s.length();
		int max_len = 0;
		string res;
		for (int i = 0; i < s.length(); ++i){
			for (int j = s.length() - 1; j >= i; --j){
				string sub = s.substr(i, j - i + 1);
				if (isPalinedrome(s.substr(i, j - i+1))){
					if (max_len < j - i+1){
						res = s.substr(i, j - i+1);
						max_len = max(max_len, j - i+1);
					}
				}
			}
		}
		return res;
	}
};
*/
// 使用dp.
class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.length();
		string res;
		if (len == 0)
			return res;
		vector<vector<int>>dp(len + 1, vector<int>(len + 1, 0));
		int max_len = 1;
		for (int i = 0; i < len; ++i){
			dp[i][i] = 1;
		}
		for (int i = 0; i < len - 1; ++i)
		{
			if (s[i] == s[i + 1])
				dp[i][i + 1] = 1;
		}
		int left = 0, right = 0;
		for (int i = 0; i < s.size(); ++i) {
			for (int j = 0; j < i; ++j){
				dp[j][i] = (s[i] == s[j] && ((i - j <2 )|| dp[j + 1][i - 1]));
				if (dp[j][i] && max_len < i - j + 1){
					max_len = i - j + 1;
					left = j;
					right = i;
				}
			}
		}
		return s.substr(left, right - left + 1);
	}
};
int main()
{
	//string s = "babad";
	string s = "cbbd";
	Solution sol;
	string t = sol.longestPalindrome(s);
	cout << t << endl;
	return 0;
}