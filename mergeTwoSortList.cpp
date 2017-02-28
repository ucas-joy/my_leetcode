#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* mergeLists(ListNode*l1, ListNode *l2)
	{
		if (l1 == NULL && l2 == NULL)
			return NULL;
		if (l1 == NULL || l2 == NULL)
			return l1 == NULL ? l2 : l1;
		ListNode dummy(-1);
		ListNode *phead = &dummy;
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *tmp = &dummy;
		ListNode *head = &dummy;
		head = phead;
		while (p1 != NULL && p2 != NULL){
			if (p1->val > p2->val){
				tmp = p2;
				p2 = p2 == NULL ? NULL : p2->next;
				phead->next = tmp;
				phead = tmp;
			}else
			{
				tmp = p1;
				p1 = p1 == NULL ? NULL : p1->next;
				phead->next = tmp;
				phead = tmp;
			}
		}
		while (p1 != NULL){
			phead->next = p1;
			phead = p1;
			p1 = p1 == NULL ? NULL : p1->next;
		}
		while (p2 != NULL){
			phead->next = p2;
			phead = p2;
			p2 = p2 == NULL ? NULL : p2->next;
		}
		phead->next = NULL;
		return head->next;
	}
};
int main()
{
	ListNode dummy(-1);
	ListNode *p1 = &dummy;
	ListNode *p2 = &dummy;
	ListNode *ph1 = &dummy;
	ListNode *ph2 = &dummy;
	ListNode *ph = &dummy;
	int a[4] = { 1,3,5,7 };
	int b[3] = { 2,4,6 };
	ph1 = p1;
	ph2 = p2;
	for(int i = 0 ; i < 4 ; ++i)
	{
		p1->next = new ListNode(a[i]);
		p1 = p1->next;
	}
	for (int j = 0; j < 3; ++j)
	{
		p2->next = new ListNode(b[j]);
		p2 = p2->next;
	}
	p1->next = NULL;
	p2->next = NULL;
	Solution sol;
	ph = sol.mergeLists(ph1->next, ph2->next);
	while (ph != NULL)
	{
		cout << ph->val << endl;
		ph = ph == NULL ? NULL : ph->next;
	}
	return 0;
}