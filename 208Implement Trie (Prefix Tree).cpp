/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
class TrieNode {
public:
	// Initialize your data structure here.
	char val;
	bool isWord;
	TrieNode *node[26];
	TrieNode() {
		val = 0;
		isWord = false;
		memset(node, 0x0, sizeof(TrieNode*) * 26);
	}
	TrieNode(char c) {
		val = c;
		isWord = false;
		memset(node, 0x0, sizeof(TrieNode*) * 26);
	}
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string word) {
		if (word.empty()){
			return;
		}
		TrieNode* pnode = root;
		for (int i = 0; i < word.length(); ++i){
			char c = word[i];
			if (pnode->node[c - 'a'] == 0){
				TrieNode *pNew = new TrieNode(c);
				pnode->node[c - 'a'] = pNew;
			}
			pnode = pnode->node[c - 'a'];
		}
		pnode->isWord = true;
	}

	// Returns if the word is in the trie.
	bool search(string word) {
		if (word.length() == 0)
			return true;
		TrieNode *pnode = root;
		for (int i = 0; i < word.length(); ++i){
			char c = word[i];
			pnode = pnode->node[c - 'a'];
			if (pnode == NULL){
				return false;
			}
		}
		return pnode->isWord;
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		if (prefix.length() == 0)
			return true;
		TrieNode *pnode = root;
		for (int i = 0; i < prefix.length(); ++i){
			char c = prefix[i];
			pnode = pnode->node[c - 'a'];
			if (pnode == NULL){
				return false;
			}
		}
		return true;
	}
	void freeTrieNode(TrieNode* pNode)
	{
		if (pNode == NULL)
			return;
		for (int i = 0; i < 26; ++i){
			TrieNode *pChild = pNode->node[i];
			if (pChild != NULL){
				free(pChild);
			}
		}
		free(pNode);
	}
	~Trie(){
		freeTrieNode(root);
	}
private:
	TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");