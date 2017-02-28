/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length()) return false;
		vector<vector<bool>>dp((s1.length() + 1), vector<bool>(s2.length() + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= s1.length(); ++i) {
			for (int j = 0; j <= s2.length(); ++j) {
				if (i + j > 0) {
					dp[i][j] = false;
					if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
						dp[i][j] = dp[i][j] | dp[i - 1][j];
					}
					if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
						dp[i][j] = dp[i][j] | dp[i][j - 1];
					}
				}
			}
		}
		return dp[s1.length()][s2.length()];
	}
};
int main()
{
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	Solution sol;
	bool is = sol.isInterleave(s1, s2,s3);
	cout << is << endl;
	return 0;
}