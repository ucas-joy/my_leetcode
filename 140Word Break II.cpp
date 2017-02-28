/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<unordered_set>
using namespace std;
class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		map<int, vector<string>>record;
		int len = s.length();
		//DPÃ¶¾Ù
		for (int i = 0; i < len; i++){
			vector<string>words;
			if (wordDict.find(s.substr(0, i + 1)) != wordDict.end())
				words.push_back(s.substr(0, i + 1));
			for (int j = 1; j <= i; ++j){
				vector<string>pres = record[j - 1];
				string post = s.substr(j, i - j + 1);
				if (!pres.empty() && wordDict.find(post) != wordDict.end()){
					words.push_back(post);
				}
			}
			record.insert(pair<int, vector<string>>(i, words));
		}
		vector<string>res;
		queue<pair<int, string>>que;
		for (auto r : record[len - 1])
			que.push(pair<int, string>(len - r.length(), r));
		while (!que.empty()){
			pair<int, string>p = que.front();
			que.pop();
			if (p.first <= 0)
				res.push_back(p.second);
			else {
				for (auto w : record[p.first - 1])
					que.push(pair<int, string>(p.first - w.length(), w + " " + p.second));
			}
		}
		return res;
	}
};
int main140()
{
	string s = "catsanddog";
	unordered_set<string>	dict = { "cat", "cats", "and", "sand", "dog" };
	Solution sol;
	vector<string> a = sol.wordBreak(s, dict);
	cout << endl;
	return 0;
}