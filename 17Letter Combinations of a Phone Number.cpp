/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
private:
	int Len;
	string digit_map[8]{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	void search(const string& digits, int pos, string path, vector<string>& v)
	{
		if (pos == Len) return;
		string s = digit_map[digits[pos] - '2'];
		for (int i = 0; s[i]; ++i)
		{
			if (pos == Len - 1) v.push_back(path + s[i]);
			else search(digits, pos + 1, path + s[i], v);
		}
	}
public:
	vector<string> letterCombinations(string digits)
	{
		Len = digits.length();
		vector<string> v;
		search(digits, 0, "", v);
		return v;
	}
};
class Solution {
private:
	int Len;
	string digit_map[8]{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	void search(const string & digits, int pos, string path, vector<string>&v)
	{
		if (pos == Len) return;
		string s = digit_map[digits[pos] - '2'];
		for (int i = 0; s[i]; ++i)
		{
			if (pos == Len - 1) v.push_back(path + s[i]);
			else search(digits, pos + 1, path + s[i], v);
		}
	}
public:
	vector<string> letterCombinations(string digits)
	{
		Len = digits.length();
		vector<string>v;
		search(digits, 0, "", v);
		return v;
	}
};
int main17()
{
	string a = "23";
	Solution sol;
	vector<string> res = sol.letterCombinations(a);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << endl;
	}
	return 0;
}