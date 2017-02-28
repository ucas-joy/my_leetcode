/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA,
it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
using namespace std;
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		set<string> res;
		vector<string> ret;
		if (s.length() <= 10)
			return ret;
		map<string, int>mp;
		int len = s.length();
		int i;
		for (i = 0; i <= len-10; ++i){
			int mp_size = mp.size();
			mp.insert(make_pair(s.substr(i,10), 1));
			if (mp_size == mp.size()){
				res.insert(s.substr(i,10));
			}
			mp_size = 0;
		}
		ret.assign(res.begin(), res.end());
		return ret;
	}
};
int main()
{
	string s1("AAAAAAAAAAAA");
	Solution sol;
	vector<string> s;
	s = sol.findRepeatedDnaSequences(s1);
	int i = 0;
	while (i < s.size()){
		cout << s[i] << endl;
		i++;
	}
	return 0;
}