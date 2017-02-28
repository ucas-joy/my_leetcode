#include <stdio.h>
#include <tchar.h>
#include<iostream>
#include<cstdlib>

struct BSNode {
	int data;
	BSNode *lChild;
	BSNode *rChild;
	BSNode() { }
	BSNode(int v) : data(v), lChild(NULL), rChild(NULL) { }
};
class BSTree
{
public:
	BSTree(void);
	~BSTree(void);

	int createTree(BSNode **root);
	int preOrder(BSNode *root);
	int inOrder(BSNode *root);
	int postOrder(BSNode *root);
	int leverOrder(BSNode *root);
};
