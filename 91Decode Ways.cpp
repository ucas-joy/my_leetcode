/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	int numDecodings(string s) {
		int len = s.length();
		if (len == 0 || s[0] == '0')
			return 0;
		if (len == 1)
			return 1;
		vector<int>dp(len + 1, 0);
		dp[0] = 1;
		for (int i = 1; i < dp.size(); ++i)
		{
			if (s[i - 1] != '0'){
				dp[i] += dp[i - 1];
			}
			if (i > 1 && atoi((s.substr(i - 2, 2)).c_str()) >= 10 && atoi((s.substr(i - 2, 2)).c_str()) <= 26){
				dp[i] += dp[i - 2];
			}
		}
		return dp[len];
	}
};

int main()
{
	string s = "12120";
	Solution sol;
	int t = sol.numDecodings(s);
	cout << t << endl;
	return 0;
}