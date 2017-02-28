/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.

Subscribe to see which companies asked this question
test case
"a     b      "  return 1
"day        "  return 3

*/
#include<iostream>
#include <string>
using namespace std;
class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.length() == 0)
			return 0;
		string s1;
		int len = s.length() - 1;
		while (len >= 0){
			while(len >= 0 && s[len] == ' '){
				len--;
			}
			if (len < 0){
				return 0;
			}
			if (len >= 0 && s[len] != ' ') {
				s1 += s[len];
				len--;
			}
			if (len < 0 || s[len] == ' ') {
				break;
			}
		}
		return s1.length();
	}
};
int main4()
{
	string s2 = "day           ";
	Solution sol;
	int i = sol.lengthOfLastWord(s2);
	cout << i << endl;
	return 0;
}