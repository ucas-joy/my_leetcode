/*
Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
#include<deque>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	void reorderList(ListNode* head) {
		/*if (head == NULL || head->next == NULL) return;

		ListNode *slow = head;
		ListNode *fast = head;
		while (fast->next != NULL && fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode *mid = slow->next;
		ListNode *last = mid;
		ListNode *pre = NULL;
		while (last != NULL) {
			ListNode *next = last->next;
			last->next = pre;
			pre = last;
			last = next;
		}
		slow->next = NULL;

		while (head != NULL && pre != NULL) {
			ListNode *next1 = head->next;
			head->next = pre;
			pre = pre->next;
			head->next->next = next1;
			head = next1;
		}*/
		ListNode dummy(-1);
		if (head == NULL || head->next == NULL) {
			return;
		}
		ListNode *fast = head;
		ListNode *slow = head;
		while (slow->next != NULL && fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode *mid = slow->next;
		ListNode *last = mid;
		ListNode *prev = NULL;
		while (last != NULL) {
			ListNode *next = last->next;
			last->next = prev;
			prev = last;
			last = next;
		}
		slow->next = NULL;
		while (head != NULL && prev != NULL) {
			ListNode *next1 = head->next;
			head->next = prev;
			prev = prev->next;
			head->next->next = next1;
			head = next1;
		}
	}
	
};
int main()
{
	ListNode head3(-1);
	ListNode *p = &head3;
	ListNode *pp1 = p;
	ListNode *pp2 = &head3;
	int a[6] = { 1,2,3,4};
	for (int i = 0; i < 4; ++i) {
		p->next = new ListNode(a[i]);
		p = p->next;
	}
	p->next = NULL;
	pp2 = pp1->next;
	Solution sol;
	sol.reorderList(pp2);
	while (pp2 != NULL) {
		cout << pp2->val << endl;
		pp2 = pp2 == NULL ? NULL : pp2->next;
	}
	return 0;
}