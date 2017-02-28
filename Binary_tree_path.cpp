/*Given a binary tree, return all root - to - leaf paths.

For example, given the following binary tree :

   1
  / \
 2   3
  \
   5
All root - to - leaf paths are :

["1->2->5", "1->3"]
*/

#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() { }
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> path;
		if (root == NULL)
			return  path;
		if (root->left == NULL, root->right == NULL) {
			char buff[1024];
			sprintf(buff, "%d", root->val);
			path.push_back(buff);
			return path;
		}
		stack<TreeNode*> stk;
		string s = "";
		string tmps = "";
		string tmps1 = "";
		TreeNode *p = root;
		TreeNode *tmproot = root;
		TreeNode dummy(-1);
		TreeNode *tmpL = &dummy;
		while (!stk.empty() || p != NULL) {
			while (p != NULL) {
				s.push_back(p->val + '0');
				s = s + "-" + ">";
				stk.push(p);
				tmpL = p;
				p = p->left;
			}
			if (!stk.empty()) {			
				p = stk.top();
				stk.pop();
				if (p->right == NULL && p->left == NULL){
					tmps = s.substr(0, s.length() - 2);
					path.push_back(tmps);
					tmps1 = s.substr(0, s.length() - 3);
					s = tmps1;	
				}		
				p = p->right;
				if (p == NULL && stk.size() != 0){
					p = stk.top();
					stk.pop();
					s = s.substr(0, (stk.size() + 1) * 3);
					p = p->right;
				}
				

			}
		}
	}
	std::string int2str(int value)
	{
		ostringstream ss;
		ss << value;
		return ss.str();
	}
};
//TreeNode * CreateTree(TreeNode *bTree)
//{
//	int input;
//	scanf("%d", &input);			//按先序建立二叉树
//	if (input == 0)
//	{
//		bTree = NULL;	//置为NULL后结束
//		return bTree;
//	}
//	bTree = (TreeNode *)malloc(sizeof(TreeNode));
//	bTree->val = input;
//	bTree->left = CreateTree(bTree->left);
//	bTree->right = CreateTree(bTree->right);
//	return bTree;
//}

int createTree(TreeNode **root, int value)
{
	if (*root == NULL)
	{
		*root = (TreeNode *)malloc(sizeof(TreeNode));
		(*root)->val = value;
		(*root)->left = NULL;
		(*root)->right = NULL;
		return  0;
	}
	else if (value < (*root)->val)
	{
		createTree(&((*root)->left), value);
	}
	else
	{
		createTree(&((*root)->right), value);
	}

}


int inOrder(TreeNode *root)		//这个是先序遍历，先根，左子树，右子树
{
		// cout << 1 << endl;
		if (root == NULL) {
			//	cout << "the tree is null !" <<endl;
			return 0;
		}
		// 	cout << 2 << endl;
		inOrder(root->left);
		cout << root->val << '\t';
		inOrder(root->right);

		return 1;
}

int main13(int argc, char *argv[])
{
		TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
		//TreeNode BTree;
		int a[] = { 3, 5, 1, 4 , 6 ,2, 0 };
		int len = sizeof(a) / sizeof(*a);
		int i = 0;
		int j = 10;
		int value;
		root->val = a[0];
		root->left = root->right = NULL;
		for (i = 1; i < len; i++)
		{
			createTree(&root, a[i]);
		};
		inOrder(root);
		Solution sol;
		vector<string> paths;
		paths = sol.binaryTreePaths(root);
		for (int i = 0; i < paths.size(); ++i)
		{
			cout << paths[i] << endl;
		}
	return 0;
}