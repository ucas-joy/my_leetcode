/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
	bool wordPattern(string pattern, string str) {
		int plen = pattern.length();
		int slen = str.length();
		if (plen  == 0&& slen == 0) {
			return true;
		}
		if (plen == 0 && slen != 0) {
			return false;
		}
		if (plen == slen) {
			return false;
		}
		int count = 0;
		int k = 0;
		while (k < slen)
		{
			if (str[k] == ' ') {
				count++;
			}
			k++;
		}
		if (count + 1 != plen) {
			return false;
		}
		string tmp = "";
		char ch;
		map<string, char>mp1;
		map<char, string> mp2;
		int i = 0;
		int j = 0;
		while (i < slen)
		{
			while(i < slen &&str[i] != ' ') {
				tmp += str[i];
				i++;
			}
			ch = pattern[j];
			if (mp1.find(tmp) == mp1.end()){			
				mp1[tmp] = ch;
			}
			else if (mp1[tmp] != ch){
				return false;
			}
			j++;
			i++;
			tmp = "";
		}
		j = 0;
		i = 0;
		while (i < slen)
		{
			 while(i < slen&&str[i] != ' ') {
				tmp += str[i];
				i++;
			}
			ch = pattern[j];
			if (mp2.find(ch) == mp2.end()) {
				mp2[ch] = tmp;
			}
			else if (mp2[ch] != tmp) {
				return false;
			}
			j++;
			i++;
			tmp = "";
		}
		return true;
	}
};

int main()
{
	string p = "abba";
	string s = "dog cat cat fish";
	Solution sol;
	bool is;
	is = sol.wordPattern(p, s);
	cout << is << endl;
	return 0;
}