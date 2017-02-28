/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int minCut(string s) {
		int len = s.length();
		if (len == 0)
			return 0;
		string s1 = s;
		reverse(s1.begin(), s1.end());
		if (s1 == s)
			return 0;
		vector<int>DP(len + 1, 0);
		DP[len] = -1;
		vector<vector<int>>dp(len, vector<int>(len, 0));
		for (int i = 0; i < len; ++i){
			dp[i][i] = 1;
		}
		for(int i = len-1; i >= 0 ; --i){
			DP[i] = INT_MAX;
			for (int j = i; j < len; ++j){
				if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]))
				{
					dp[i][j] = 1;
					DP[i] = min(DP[i], DP[j + 1] + 1);
				}
			}
		}
		return DP[0];
	}
};
int main132()
{
	string s = "aab";
	//string s = "abc";
	Solution sol;
	int t = sol.minCut(s);
	cout << t << endl;
	return 0;
}