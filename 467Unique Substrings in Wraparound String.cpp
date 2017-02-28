/*
Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", 
so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

Now we have another string p. Your job is to find out how many unique non-empty substrings of p are present in s.
In particular, your input is the string p and you need to output the number of different non-empty substrings of p in the string s.

Note: p consists of only lowercase English letters and the size of p might be over 10000.

Example 1:
Input: "a"
Output: 1

Explanation: Only the substring "a" of string "a" is in the string s.
Example 2:
Input: "cac"
Output: 2
Explanation: There are two substrings "a", "c" of string "cac" in the string s.
Example 3:
Input: "zab"
Output: 6
Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of string "zab" in the string s.
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<string>
#include<vector>
#include <numeric>
#include<algorithm>
using namespace std;
class Solution {
public:
	int findSubstringInWraproundString(string p) {
		vector<int>cnt(26, 0);
		int len = 0;
		for (int i = 0; i < p.length(); ++i) {
			if (i > 0 && (p[i] - p[i - 1] == 1 || p[i - 1] - p[i] == 25)) {
				++len;
			}
			else{
				len = 1;
			}
			int t = p[i] - 'a';
			cnt[t] = max(cnt[t], len);
		}
		return accumulate(cnt.begin(), cnt.end(), 0);
	}
};
int main()
{
	string s = "zab";
	Solution sol;
	int t = sol.findSubstringInWraproundString(s);
	cout << t << endl;
	return 0;
}