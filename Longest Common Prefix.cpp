/*Write a function to find the longest common prefix string amongst an array of strings.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string s = "";
		if (strs.size() == 0)
			return s;
		if (strs.size() == 1)
			return strs[0];
		
		if (strs.size() == 2){
			s = FindLCP(strs[0], strs[1]);
			return s;
		}
		s = FindLCP(strs[0], strs[1]);
		for (int i = 2; i < strs.size(); ++i)
		{
			s = FindLCP(s, strs[i]);
		}
		return s;
	}
	string FindLCP(string &s1, string &s2) {
		string s3 = "";
		int len1 = s1.length()-1;
		int len2 = s2.length() - 1;
		int index1 = 0;
		int index2 = 0;
		while(index1 <= len1 && index2 <= len2&&s1[index1] == s2[index2]){
			s3 += s1[index1];
				index1++;
				index2++;
		}
		return s3;
		
	}
};
int main333()
{
	vector<string>s1 = { "abcd","aaaa","abc","das" };
	//vector<string> s1 = {};
	Solution sol;
	string s4;
    s4 = 	sol.longestCommonPrefix(s1);
	cout << s4 << endl;
	return 0;
}