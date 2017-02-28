/*
Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 ¡ú a2
                     ¨K
                      c1 ¡ú c2 ¡ú c3
                    ¨J
B:     b1 ¡ú b2 ¡ú b3
begin to intersect at node c1.

otes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
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
#include<stack>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode dummy(-1);
		ListNode *p1 = &dummy;
		ListNode *p2 = &dummy;
		p1 = headA;
		p2 = headB;
		if (p1 == NULL && p2 == NULL) {
			return NULL;
		}
		int len1 = 0;
		int len2 = 0;
		int len = 0;
		int len3 = 0;
		while (p1 != NULL) {
			len1++;
			p1 = p1 == NULL ? NULL : p1->next;
		}
		while (p2 != NULL) {
			len2++;
			p2 = p2 == NULL ? NULL : p2->next;
		}
		len = (len1 >= len2 ? len2 : len1);
		p1 = headA;
		p2 = headB;
		if (len1 > len2) {
			len3 = len1 - len2;
			while (len3--)
			{
				p1 = p1->next;

			}
		}
		if (len2 > len1) {
			len3 = len2 - len1;
			while (len3--) {
				p2 = p2->next;
			}
		}
		while (len--) {
			if (p1->val == p2->val) {
				return p1;
				break;
			}
			else
			{
				p1 = p1->next;
				p2 = p2->next;
			}

		}
		return NULL;
	}
};
int main31111331()
{
	ListNode head1(-1);
	ListNode *p1 = &head1;
	ListNode *p2 = &head1;
	ListNode *p3 = &head1;
	ListNode *pp1 = p1;
	ListNode *pp2 = p2;
	int a[5] = { 1,2,4,5,9 };
	int b[6] = { 2,2,2,4,5,9 };
	for (int i = 0; i < 5; ++i) {
		p1->next = new ListNode(a[i]);
		p1 = p1->next;
	}
	for (int i = 0; i < 6; ++i)
	{
		p2->next = new ListNode(b[i]);
		p2 = p2->next;
	}
	Solution sol;
	p3 = sol.getIntersectionNode(pp1->next, pp2->next);
	cout << p3->val << endl;
	return 0;


}