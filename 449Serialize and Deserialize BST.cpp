/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer,
or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm
should work. You just need to ensure that a binary search tree can be serialized to a string and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<sstream>
#include<string>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		if (root == NULL) return " #";
		string ans = " " + to_string(root->val);
		return ans + serialize(root->left) + serialize(root->right);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		istringstream is(data);
		return deDFS(is);

	}
	TreeNode *deDFS(istringstream &is)
	{
		string str;
		is >> str;
		if (str == "#") return NULL;
		TreeNode *root = new TreeNode(atoi(str.c_str()));
		root->left = deDFS(is), root->right = deDFS(is);
		return root;
	}
};
 