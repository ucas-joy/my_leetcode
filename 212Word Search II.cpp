/*
Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
['o','a','a','n'],
['e','t','a','e'],
['i','h','k','r'],
['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.

click to show hint.

Subscribe to see which companies asked this question
*/
/*#include<vector>
#include<iostream>
#include<string>
using namespace std;
class TrieNode {
public:
	vector<TrieNode*>child;
	bool isWord;
	TrieNode() :child(vector<TrieNode*>(26, NULL)), isWord(false) {}
};
class Trie {
public:
	Trie() :root(new TrieNode()) {}
	~Trie(){
		delNode(root);
	}
	void delNode(TrieNode *n){
		for (int i = 0; i < 26; ++i){
			if (n->child[i]) delNode(n->child[i]);
		}
		delete n;
	}
	TrieNode *getRoot(){
		return root;
	}
	void insert(string word){
		TrieNode *n = root;
		for (auto ch : word) {
			if (n->child[ch - 'a'] == NULL)
				n->child[ch - 'a'] = new TrieNode();
			n = n->child[ch - 'a'];
		}
		n->isWord = true;
	}
private:
	TrieNode *root;
};
class Solution {
	void chkExist(vector<vector<char>>& board, TrieNode* n, vector<string>& ret, string curStr, int r, int c){
		n = n->child[board[r][c] - 'a'];
		if (n){
			curStr += board[r][c];
			if (n->isWord) {
				ret.push_back(curStr);
				n->isWord = false;
			}
			char ch = board[r][c];
			board[r][c] = 0;
			if (r > 0 && board[r - 1][c])
				chkExist(board, n, ret, curStr, r - 1, c);
			if (r < board.size() - 1 && board[r + 1][c])
				chkExist(board, n, ret, curStr, r + 1, c);
			if (c > 0 && board[r][c - 1])
				chkExist(board, n, ret, curStr, r, c - 1);
			if (c < board[0].size() - 1 && board[r][c + 1])
				chkExist(board, n, ret, curStr, r, c + 1);
			board[r][c] = ch;
		}
	}
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> ret;
		int row = board.size();
		if (!row) return ret;
		int col = board[0].size();
		if (!col) return ret;
		Trie t;
		for (auto s : words) t.insert(s);
		for (int i = 0; i<row; ++i) {
			for (int j = 0; j<col; ++j) {
				chkExist(board, t.getRoot(), ret, "", i, j);
			}
		}
		return ret;
	}
};
*/
