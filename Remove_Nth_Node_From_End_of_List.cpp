/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode dummp(-1);
		if (head == NULL) {
			return dummp.next;
		}
		ListNode *p = head;
		ListNode *p1 = &dummp;
		ListNode *p2 = &dummp;
		ListNode *p3 = &dummp;
		int len = 0;
		while (p != NULL) {
			len++;
			p = p == NULL ? NULL : p->next;
		}
		p = head;
		if (n == len) {
			p1 = p;
			p = p->next;
			delete p1;
			return p;
		}
		
		len = len - n-1;
		p2 = p;
		while (len--) {
			p = p->next;
		}
		p1 = p;
		p3 = p->next;
		p = p3->next;
		p1->next = p;
		delete p3;
		
		return  p2;
	}
};
int main13133113()
{
	ListNode head1(-1);
	ListNode *p = &head1;
	ListNode *pp1 = p;
	ListNode *p1 = &head1;
	int a[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 5; ++i)
	{
		p->next = new ListNode(a[i]);
		p = p->next;
	}
	p = NULL;
	Solution sol;
	p1 = sol.removeNthFromEnd(pp1->next,2);
	while (p1 != NULL) {
		cout << p1->val << endl;
		p1 = p1 == NULL ? NULL : p1->next;
	}
	return 0;

}