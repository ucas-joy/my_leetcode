/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	string shortestPalindrome(string s) {
		int n = s.size();
		if (n == 0) return s;
		int i = n;
		string v = s;
		reverse(v.begin(), v.end());
		string a, b,c;
		for (; i >= 1; --i)
		{
			a = s.substr(0, i);// 0开始，i个字符
		    b = s.substr(n - i);//(n-i)位置后的字符
			if (s.substr(0, i) == v.substr(n - i)) break;
		}
		for (; i < s.size(); i += 2)
		//	 c = s[i];
			s = s[i] + s;
		return s;
	}
};

int main214()
{
	string s = "abcd";
	Solution sol;
	string t = sol.shortestPalindrome(s);
	cout << t << endl;
	return 0;
}
