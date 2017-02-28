/*
Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000)
string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters 
without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
	bool isSubsequence(string s, string t) {
		if (s.length() == 0)
			return true;
		int i, j;
		int count = 0;
		for (i = 0, j = 0; i < s.length(), j < t.length(); ){
			if (s[i] == t[j]){
				i++;
				j++;
				count++;
			}
			else{
				j++;
			}
		}
		if (count == s.length()) {
			return true;
		}
		return false;
	}
};
int main(void)
{
	string s = "axc", t = "ahbgdc";
	Solution sol;
	bool t1;
	t1 = sol.isSubsequence(s, t);
	cout << t1 << endl;
	return 0;
}