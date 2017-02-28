/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int countSegments(string s) {
		int len = s.length();
		if (len == 0)
			return 0;
		int count = 1;
		int i = 0;
		while (i < s.length() && isspace(s[i])) {
			i++;
		}
		if (i == s.length()){
			return 0;
		}
		for (; i < s.length()-1; ++i){
			if ((isspace(s[i]) && !isspace(s[i + 1]))){
				count++;
			}
		}
		return count;
	}
};
int main()
{
	//string s = "Hello, my name is John";
	string s = "                 ";
	Solution sol;
	int t = sol.countSegments(s);
	cout << t << endl;
	return 0;
}