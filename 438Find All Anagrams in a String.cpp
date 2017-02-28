/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//³¬Ê±
//class Solution {
//public:
//	vector<int> findAnagrams(string s, string p) {
//		vector<int>res;
//		if (p.length() > s.length())
//			return res;
//		
//		if (s.length() == 0)
//			return res;
//		int len = p.length();
//		sort(p.begin(), p.end());
//		for (int i = 0; i <= s.length()- len; ++i){
//			string tmp = s.substr(i, len);
//			sort(tmp.begin(), tmp.end());
//			if (tmp == p){
//				res.push_back(i);
//			}
//		}
//		return res;
//	}
//};

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int>res;
		if (s.length() == 0)
			return res;
		vector<int>hash(256,0);
		int lenp = p.length();
		int len = s.length();
		for (int k = 0; k < lenp; ++k){
			hash[p[k]]++;
		}
		int i = 0;
		while (i < len){
			bool  succ = true;
			vector<int> tmp = hash;
			for (int j = i; j < i + lenp; ++j){
				if (--tmp[s[j]] < 0){
					succ = false;
					break;
				}
			}
			if (succ) {
				res.push_back(i);
			}
			++i;
		}
		return res;
	}
};
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		if (s.size() < p.size()) return res;

		int n = s.size(), k = p.size(), cnt[26] = {}, i = 0;
		for (char c : p) cnt[c - 'a']++;
		
		for (int j = 0; j < n; ++j)
		{
			int idx = s[j] - 'a';
			if (--cnt[idx] > 0)
			{
				k--;
			}else 
			{
				while (cnt[idx] < 0)
					if (++cnt[s[i++] - 'a'] > 0) k++;
			}
			if (k == 0)
				res.push_back(i);
		}
		

		return res;
	}
};
int main()
{
	//string s = "abab";
	//string p = "ab";

	string s = "cbaebabacd"; 
	string p = "abc";
	Solution sol;
	vector<int>ret;
	ret = sol.findAnagrams(s, p);
	for (int i = 0; i < ret.size(); ++i)
	{
		cout << ret[i] << endl;
	}
	return 0;
}
