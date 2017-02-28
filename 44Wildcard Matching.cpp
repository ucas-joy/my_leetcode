/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		int len_s = s.length();
		int len_p = p.length();
		if (len_s == 0 && len_p == 0)
			return true;
		// a********b*******c  ===> a*b*c
		//简化字符串，空间节约
		int index = 0;
		for (int i = 0; i < min(len_p, len_s); ++i) {
			if (s[i] == p[i]) {
				index = i;
			}
			else if (s[i] != p[i]) {
				break;
			}
		}
		int writeIndex = 0;
		bool isFirst = true;
		for (int i = 0; i < len_p; ++i){
			if (p[i] == '*'){
				if (isFirst){
					p[writeIndex++] = p[i];
					isFirst = false;
				}
			}else {
				p[writeIndex++] = p[i];
				isFirst = true;
			}
		}
		
		vector<vector<bool>>dp(len_s + 1, vector<bool>(writeIndex + 1));
		if (writeIndex > 0 && p[0] == '*'){
			dp[0][1] = true;
		}
		dp[0][0] = true;
		for (int i = 1; i < dp.size(); ++i){
			for(int j = 1 ; j < dp[0].size();++j)
				if (p[j - 1] == '?' || s[i-1] == p[j-1]){
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (p[j - 1] == '*'){
					dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
				}
			}
		return dp[len_s][writeIndex];
		}
};
int main444()
{
	//string s = "xaylmz";
	//string p = "x?y*z";
	string s = "";
	string p = "*";
	Solution sol;
	bool is = sol.isMatch(s, p);
	cout << is << endl;
	return 0;
}