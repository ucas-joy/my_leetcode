/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]
Note:
All words have the same length.
All words contain only lowercase alphabetic characters.
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
using namespace std;
class Solution {
public:
	void DFS(set<pair<string, int>> st, vector<string> vec){
		for (auto val : st){
			vec.push_back(val.first);
			if (hash.count(val.first) == 0){
				reverse(vec.begin(), vec.end());
				return res.push_back(vec);
			}
			DFS(hash[val.first], vec);
			vec.pop_back();
		}
	}
	vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
		wordList.insert(beginWord);
		wordList.insert(endWord);	
		que.push(make_pair(beginWord, 1));
		wordList.erase(beginWord);
		while (!que.empty()){
			auto val = que.front();
			que.pop();
			for (int i = 0; i < val.first.size(); ++i) {
				string str = val.first;
				for (int j = 0; j < 26; ++j){
					str[i] = 'a' + j;
					if (wordList.count(str) == 1){
						que.push(make_pair(str, val.second + 1));
						hash[str].insert(val);
						wordList.erase(str);
					}
					else if (hash.count(str) && hash[str].begin()->second == val.second)
						hash[str].insert(val);
				}
			}
		}
		DFS(hash[endWord], vector<string>{endWord});
		return res;
	}
	vector<vector<string>>res;
	unordered_map<string, set<pair<string, int>>> hash;
	queue<pair<string, int>>que;
};
