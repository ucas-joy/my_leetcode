/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
		wordList.insert(beginWord);
		wordList.insert(endWord);
		queue<pair<string, int>>que;
		que.push(make_pair(beginWord, 1));
		wordList.erase(beginWord);
		while (!que.empty()){
			auto val = que.front();
			que.pop();
			if (val.first == endWord) return val.second;
			for (int i = 0; i < val.first.size(); ++i) {
				string str = val.first;
				for (int j = 0; j < 26; ++j){
					str[i] = 'a' + j;
					if (wordList.count(str) == 1){
						que.push(make_pair(str, val.second + 1));
						wordList.erase(str);
					}
				}
			}
		}
		return 0;
	}
};

int main127()
{
	string beginWord = "hit";
	string 	endWord = "cog";
	unordered_set<string>	wordList = { "hot", "dot", "dog", "lot", "log" };
	Solution sol;
	int t = sol.ladderLength(beginWord, endWord, wordList);
	cout << t << endl;
	return 0;
}


