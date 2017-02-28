/*
You are given a string, s, and a list of words, words, that are all of the same length. 
Find all starting indices of substring(s) in s that is a concatenation of
each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int>res;
		if (words.size() > s.size()) return res;
		int n = s.size(), nw = words.size();
		map<string, int>mp,tmp_mp;
		map<string, int>::iterator it;
		for (int i = 0; i < nw; ++i){
			string ret = words[i];
			it = mp.find(ret);
			if (it != mp.end()){
				it->second++;
			}
			else{
				mp.insert(make_pair(ret, 1));
			}
		}
		tmp_mp = mp;
		int k;
		int tmp_j = 0;
		for (int j = 0; j < n;++tmp_j){
		//	 tmp_j = j;
			 j = tmp_j;
			 for (k = 0; k < nw;) {
				if (j + words[k].size() <= n){
					it = mp.find(s.substr(j, words[k].size()));
					if (it != mp.end()) {
						it->second--;
						if (it->second >= 0) {
							j = j + words[k].size();
							k++;
							continue;
						}
						if (it->second < 0) {
							j = tmp_j + 1;
							tmp_j = j;
							mp = tmp_mp;
							k = 0;
							continue;
						}
					}
					else {
						j = tmp_j;
						j = j + 1;
						tmp_j = j;
						k = 0;
						mp = tmp_mp;
					}
				}
				else
				{
					break;
				}
			}
			if (k == nw ) {
				res.push_back(tmp_j);
				k = 0;
				mp = tmp_mp;
			}
		}
		return res;
	}
};


int main30()
{   
	//string s = "barfoothefoobarman";
	//string s = "barfoofoobarthefoobarman"; //[6,9,12];
	//string c = "the";
	//string a = "foo";
	//string b = "bar";
	string s = "wordgoodgoodgoodbestword";//[8]
	string a = "word", b = "good", c = "best", d = "good";
	vector<string> t;
	t.push_back(a);
	t.push_back(b);
	t.push_back(c);
	t.push_back(d);
	Solution sol;
	vector<int>m = sol.findSubstring(s, t);
	int i = 0;
	while (i < m.size())
	{
		cout << m[i] << endl;
		i++;
	}
	return 0;
}