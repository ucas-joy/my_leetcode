/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.
You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
/*class Solution {
public:
	int maxProduct(vector<string>& words) {
		if (words.size() == 0)
			return 0;
		int maxP = 0;
		for (int i = 0; i < words.size(); ++i)
		{
			for (int j = i + 1; j < words.size(); ++j)
			{
				if (!is_share_com(words[j], words[i]))
				{
					maxP = max(maxP, (int)(words[j].length() * words[i].length()));
				}
			}
		}
		return maxP;
	}
		bool is_share_com(string &a, string &b)
		{
			int hash1[128] = { 0 };
			for (int i = 0; i < a.length(); ++i)
			{
				hash1[a[i]]++;
			}
			for (int i = 0; i < b.length(); ++i)
			{
				if (hash1[b[i]] > 0)
				{
					return true;
				}
			}
			return false;
		}

};*/
class Solution {
public:
	int maxProduct(vector<string>& words) {
		if (words.size() == 0)
			return 0;
		vector<int>str2int;
		int maxP = 0;
		for (int i = 0; i < words.size(); ++i){
			int temp = 0;
			for (int j = 0; j < words[i].size(); ++j){
				temp |= 1 << (words[i][j] - 'a');
			}
			str2int.push_back(temp);
		}
		for (int i = 0; i < str2int.size(); i++){
			for (int j = i + 1; j < str2int.size(); ++j){
				if (!(str2int[i] & str2int[j])){
					maxP = max(maxP, static_cast<int>(words[i].length() * words[j].length()));
				}
			}
		}
		return maxP;
	}
};
int main()
{
	vector<string> t = { "a","aa","aaa","aaaa" };
	Solution sol;
	int i = sol.maxProduct(t);
	cout << i << endl;
	return 0;
}