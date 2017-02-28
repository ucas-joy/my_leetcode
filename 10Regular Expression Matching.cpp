/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ¡ú false
isMatch("aa","aa") ¡ú true
isMatch("aaa","aa") ¡ú false
isMatch("aa", "a*") ¡ú true
isMatch("aa", ".*") ¡ú true
isMatch("ab", ".*") ¡ú true
isMatch("aab", "c*a*b") ¡ú true
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	bool isMatch(string s, string p) {
		vector<vector<bool>>dp(s.length() + 1, vector<bool>(p.length() + 1, false));
		dp[0][0] = true;
		for (int i = 2; i < p.length()+1; ++i) {
			if (p[i - 1] == '*'){
				dp[0][i] = dp[0][i - 2];
			}
		}	
		for (int i = 1; i < dp.size(); ++i) {
			for (int j = 1; j < dp[0].size(); ++j){
				if (p[j - 1] == '.' || s[i - 1] == p[j - 1]){
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if(p[j-1] == '*'){
					if (j >= 2){
						dp[i][j] = dp[i][j - 2];
						if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
							dp[i][j] = dp[i][j] | dp[i - 1][j];
						}
					}	
				}
				else{
					dp[i][j] = false;
				}
			}
		}
		return dp[s.length()][p.length()];
	}
};
int main10()
{
	string s = "aab";
	string p = "c*a*b";
	Solution sol;
	bool is = sol.isMatch(s, p);
	cout << is << endl;
	return 0;
}