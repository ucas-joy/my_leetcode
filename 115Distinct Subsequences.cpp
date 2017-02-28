/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters
without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	int numDistinct(string s, string t) {
		int m = s.length();
		int n = t.length();
		vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
		for (int j = 0; j <= n; ++j){
			dp[0][j] = 1;
		}
		for (int i = 0; i <= m; ++i) {
			dp[i][0] = 0;
		}
		for (int j = 1; j <= n; ++j) {
			for (int i = 1; i <= m; ++i)
			{
				dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
			}
		}
		return dp[m][n];
	}
};
int main()
{
	string s = "rabbbit";
	string t = "rabbit";
	Solution sol;
	int t = sol.numDistinct(s, t);
	cout << t << endl;
	return 0;
}