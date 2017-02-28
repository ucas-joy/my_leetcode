/*Given a binary search tree(BST), find the lowest common ancestor(LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia : ��The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants(where we allow a node to be a descendant of itself).��

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
			if (p1) { // �ߵ������
				s1.push(p1);
				p1 = p1->left;
			}
			else{ // ����
				TreeNode *p2 = s1.top() ; //ȡջ��
				if (p2->right && p2->right != r){ // ������������ڣ��Ҳ�û�б����ʣ�
					p2 = p2->right; // ת����
					s1.push(p2); // ѹ��ջ
					p2 = p2->left; // ���ߵ�����
				}
				else{
					tmp = s1.top(); // ���� ��ջ��Ԫ�ر��浽tmp��
					if (tmp == p || tmp == q){ // �Ա� tmp �� p  q �Ƿ����
						count++;
					}
					if (count == 1){ // �ҵ�p q ����һ��
						s2 = s1; // ��ǰջ���ݵ�s2.
						while (!s1.empty()){  // ͬʱ��ջ��Ԫ�ر��浽 v1 ��
							v1.push_back(s1.top());
							s1.pop();
						}
						s1 = s2; // ��ԭs1.
					}
					if (count == 2){ // p q ���ҵ�
						s2 = s1; // ����
						while (!s1.empty()) // ջ��Ԫ�ر��浽v2��
						{
							v2.push_back(s1.top());
							s1.pop();
						}
						s1 = s2; // ��ԭs2.
						break; // ���������㶼�ҵ�����ô����ֹѭ��
					}
					s1.pop();// ����Ԫ��
					r = tmp; // ��¼ջ��Ԫ�أ�Ҳ���������ʹ��Ľ��
					tmp = NULL; //�������������tmp ָ��
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