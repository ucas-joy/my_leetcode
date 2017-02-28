/*Given a binary search tree(BST), find the lowest common ancestor(LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia : “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants(where we allow a node to be a descendant of itself).”

_______6______
/ \            \
___2__       ___8__
/ \ / \        / \
0      _4     7   9
/ \
3   5
For example, the lowest common ancestor(LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace  std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) {
			return NULL;
		}
		TreeNode *r = NULL;
		stack<TreeNode*> s1,s2;
		vector<TreeNode*> v1,v2; 
		int count = 0; 
		TreeNode *p1 = root;
		TreeNode *tmp = NULL;
		while (p1 || !s1.empty()) {
			if (p1) { // 走到最左边
				s1.push(p1);
				p1 = p1->left;
			}
			else{ // 向右
				TreeNode *p2 = s1.top() ; //取栈顶
				if (p2->right && p2->right != r){ // 如果右子树存在，且并没有被访问，
					p2 = p2->right; // 转向右
					s1.push(p2); // 压入栈
					p2 = p2->left; // 再走到最左
				}
				else{
					tmp = s1.top(); // 否则 将栈顶元素保存到tmp中
					if (tmp == p || tmp == q){ // 对比 tmp 与 p  q 是否相等
						count++;
					}
					if (count == 1){ // 找到p q 其中一个
						s2 = s1; // 当前栈备份到s2.
						while (!s1.empty()){  // 同时将栈中元素保存到 v1 中
							v1.push_back(s1.top());
							s1.pop();
						}
						s1 = s2; // 还原s1.
					}
					if (count == 2){ // p q 都找到
						s2 = s1; // 备份
						while (!s1.empty()) // 栈中元素保存到v2中
						{
							v2.push_back(s1.top());
							s1.pop();
						}
						s1 = s2; // 还原s2.
						break; // 如果两个结点都找到，那么就终止循环
					}
					s1.pop();// 弹出元素
					r = tmp; // 记录栈顶元素，也就是最后访问过的结点
					tmp = NULL; //结点访问完后，重置tmp 指针
				}
			}
		}
		for (int i = 0; i < v1.size(); ++i) {
			for (int j = 0; j < v2.size(); ++j)
			{
				if (v1[i]->val == v2[j]->val) {
					return v2[j];
				}
			}
		}
	}
};

TreeNode* createTree(TreeNode **root) {
	int value;
	cin >> value;
	if (value == -1) {
		*root = NULL;
	}
	else
	{
		//BSNode *newNode = new BSNode();
		//newNode->data = value;
		*root = new TreeNode(value);
		cout << "generating node " << value << endl;
		cout << "generate left tree:" << endl;
		createTree(&(*root)->left);
		cout << "generate right tree:" << endl;
		createTree(&(*root)->right);

	}
	//cout << "Over" << value << endl;
	return *root;
}
int main1231231()
{
	TreeNode *root = NULL;
	createTree(&root);
	Solution sol;
	TreeNode *k = sol.lowestCommonAncestor(root, root, root->left);
	cout << k->val << endl;

	return 0;


}
/*
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode *cur = root;
		while (cur != NULL) {
			if (cur->val > p->val && cur->val > q->val)  cur = cur->left;
			else if (cur->val < p->val && cur->val < q->val)  cur = cur->right;
			else return cur;
		}
	}
};
*/