/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	bool repeatedSubstringPattern(string str) {
		if (str.length() <= 1)
			return false;
		string sub;
		string sub1;
		bool flag = false;
		bool found = false;
		int len = str.length();
		// "abcabcabcabc"
		for (int i = 1; i <= len / 2; ++i){
			 sub = str.substr(0, i);
			int step = sub.length();
			if (len % step != 0){
				continue;
			}
			for (int j = i; j+step <= len; j = j + step){
				sub1 = str.substr(j,  step);
				if (sub == sub1) {
					flag = true;
				}
				else{
					flag = false;
					break;
				}
				if (j + step == len) {
					found = true;
					break;
				}
			}
			if (found == true)
				break;
		}
		return flag;
	}
};
int main()
{
	//string s = "abcabcabcabc";
	//string s = "abab";
	//string s = "aba";
	string s = "a";
	Solution sol;
	bool is = sol.repeatedSubstringPattern(s);
	cout << is << endl;
	return 0;
}