/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode dummy(-1);
		ListNode *p1 = head;
		ListNode *p2 = &dummy;
		ListNode *p3 = &dummy;
		ListNode *p4 = &dummy;
		if (p1 == NULL) {
			return NULL;
		}
		while(p1 != NULL&&p1->val == val ) {
			p2 = p1;
			p1 = p1 == NULL ? NULL:p1->next;
			delete p2;
			ListNode *p2 = &dummy;
		}
		if (p1 == NULL) {
			return NULL;
		}
		p3 = p1;
		while (p1!= NULL) {
			p2 = p1;
			if (p1->next != NULL &&p1->next->val == val) {	
				p4 = p1->next;
				if (p4->next != NULL) {
					p2->next = p4->next;
					delete p4;
					p1 = p2;
					ListNode *p4 = &dummy;
				}
				else
				{
					p2->next = NULL;
					delete p4;
					p1 = p2->next;
				}
			}
			else {
				p1 = p1 == NULL ? NULL : p1->next;
			}
			
		}
		return p3;
	}
};
int main3344()
{
	ListNode head1(-1);
	ListNode *p = &head1;
	ListNode *pp1 = p;
	ListNode *p1 = &head1;
	int a[4] = { 1,2,2,1 };
	for (int i = 0; i < 4; ++i)
	{
		p->next = new ListNode(a[i]);
		p = p->next;
	}
	p = NULL;
	Solution sol;
	p1 = sol.removeElements(pp1->next, 2);
	while (p1 != NULL) {
		cout << p1->val << endl;
		p1 = p1 == NULL ? NULL : p1->next;
	}
	return 0;
}