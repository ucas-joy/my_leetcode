// tree.cpp : 定义控制台应用程序的入口点。
//

#include "tree.h"
using namespace std;
BSTree::BSTree(void)
{
}
BSTree :: ~BSTree(void)
{
}
int BSTree::createTree(BSNode **root) {
	int value;
	cin >> value;
	if (value == -1) {
		*root = NULL;
	}
	else
	{
		//BSNode *newNode = new BSNode();
		//newNode->data = value;
		*root = new BSNode(value);
		cout << "generating node " << value << endl;
		cout << "generate left tree:" << endl;
		createTree(&(*root)->lChild);
		cout << "generate right tree:" << endl;
		createTree(&(*root)->rChild);

	}
	//cout << "Over" << value << endl;
	return 1;
}
int BSTree::preOrder(BSNode *root) {
	// cout << 1 << endl;
	if (root == NULL) {
		//	cout << "the tree is null !" <<endl;
		return 0;
	}
	// 	cout << 2 << endl;
	cout << root->data << '\t';
	preOrder(root->lChild);
	preOrder(root->rChild);

	return 1;
}
int BSTree::inOrder(BSNode *root) {
	if (root == NULL) {
		return 0;
	}
	inOrder(root->lChild);
	cout << root->data << '\t';
	inOrder(root->rChild);;

	return 1;
}

int BSTree::postOrder(BSNode *root) {
	if (root == NULL) {
		return 0;
	}
	postOrder(root->lChild);
	postOrder(root->rChild);
	cout << root->data << '\t';
	return 1;
}

