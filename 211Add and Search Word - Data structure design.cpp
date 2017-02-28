/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.
*/
#include<string>
using namespace std;
class TrieNode
{
public:
	TrieNode(){
		val = 0;
		isWord = false;
		memset(node, 0x0, sizeof(TrieNode*) * 26);
	}
	TrieNode(char c){
		val = c;
		isWord = false;
		memset(node, 0x0, sizeof(TrieNode*) * 26);
	}
	char val;
	bool isWord;
	TrieNode *node[26];
};
class WordDictionary {
public:
	WordDictionary()
	{
		root = new TrieNode();
	}
	// Adds a word into the data structure.
	void addWord(string word) { 
		if (word.length() == 0)
			return;
		TrieNode *pnode = root;
		for (int i = 0; i < word.size(); ++i)
		{
			char c = word[i];
			if (pnode->node[c - 'a'] == 0)
			{
				TrieNode *pNew = new TrieNode(c);
				pnode->node[c - 'a'] = pNew;
			}
			pnode = pnode->node[c - 'a'];
		}
		pnode->isWord = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		if (word.length() == 0)
			return true;
		return query(word.c_str(), root);
	}
	bool query(const char* word, TrieNode* node) {
		TrieNode* pnode = node;
		for (int i = 0; word[i]; i++) {
			if (pnode && word[i] != '.')
				pnode = pnode->node[word[i] - 'a'];
			else if (pnode && word[i] == '.') {
				TrieNode* tmp = pnode;
				for (int j = 0; j < 26; j++) {
					pnode = tmp->node[j];
					if (query(word + i + 1, pnode))
						return true;
				}
			}
			else break;
		}
		return pnode && pnode->isWord;
	}
private:
	TrieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");