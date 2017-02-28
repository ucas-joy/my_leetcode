/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node
number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
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
	ListNode* oddEvenList(ListNode* head) {
		ListNode dummy(-1);
		ListNode *p = head;
		ListNode *p1 = &dummy;
		ListNode *phead = &dummy;
		ListNode *pend = &dummy;
		if (p == NULL){
			return p;
		}
		phead = p;
		int len = 0;
		while (p != NULL){
			pend = p;
			len++;
			p = p == NULL ? NULL : p->next;
		}
		p = phead;
		if (len == 2)
			return phead;
		int tmp_len = 0;
		while (p != NULL &&tmp_len < len/2){
			ListNode *pre = p;
			p = p == NULL ? NULL : p->next;
			if (p != NULL&& tmp_len < len/2){
				pre->next = p->next == NULL ? NULL : p->next;
				ListNode *ptmp = p;
				pend->next = ptmp;
				pend = ptmp;
				pend->next = NULL;
				p = pre;
				p = p == NULL ? NULL : p->next;
				tmp_len++;
			}
		}
		return phead;
	}
};
int main328()
{
	ListNode dummy(-1);
	ListNode *p1 = &dummy;
	ListNode *head = p1;
	ListNode *ph = &dummy;
	//int a[8] = { 1,2,3,4,5,6,7,8 };
	//int a[5] = { 1,2,3,4,5 };
	int a[2] = { 1,1 };
	for (int i = 0; i < 2; ++i) {
		p1->next = new ListNode(a[i]);
		p1 = p1->next;
	}
	p1 = NULL;
	Solution sol;
	ph = sol.oddEvenList(head->next);
	while (ph != NULL) {
		cout << ph->val << endl;
		ph = ph == NULL ? NULL : ph->next;
	}
	return 0;
}