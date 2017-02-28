/*
Reverse a singly linked list.

click to show more hints.

Subscribe to see which companies asked this question
*/


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL) {
			return head;
		}

		ListNode dummy(-1);
		ListNode *p1 = head;
		ListNode *p2 = head;
		ListNode *tmp = &dummy;
		ListNode *p3 = &dummy;
		while (p1->next != NULL) {
			tmp = p1->next;
			if (tmp->next != NULL) {
				p1->next = tmp->next;
				 tmp->next = p2;
				 p2 = tmp;
			}
			else
			{
				p1->next = NULL;
				tmp->next = p2;
				p2 = tmp;
			}
		}
		return p2;
	}
};
int main()
{
	ListNode head1(-1);
	ListNode *p = &head1;
	ListNode *pp1 = p;
	ListNode *p1 = &head1;
	int a[4] = { 1,2,3,4 };
	for (int i = 0; i < 4; ++i)
	{
		p->next = new ListNode(a[i]);
		p = p->next;
	}
	p = NULL;
	Solution sol;
	p1 = sol.reverseList(pp1->next);
	while (p1 != NULL)
	{
		cout << p1->val << endl;
		p1 = p1 == NULL ? NULL : p1->next;
	}
	return 0;
}