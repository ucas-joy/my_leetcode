/*

Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Subscribe to see which companies asked this question
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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 != NULL) {
			return l2;
		}
		if (l1 != NULL && l2 == NULL) {
			return l1;
		}
		ListNode dummy(-1);
		ListNode *prev = &dummy;
		ListNode *pa = l1;
		ListNode *pb = l2;
		while (pa != NULL && pb != NULL) {
			//pa = pa == NULL ? NULL : pa->next, pb = pb == NULL ? NULL : pb->next) {
			if (pa->val > pb->val) {
				prev->next = new ListNode(pb->val);
				pb = pb == NULL ? NULL : pb->next;
				prev = prev->next;
			}
			else if (pa->val < pb->val) {
				prev->next = new ListNode(pa->val);
				pa = pa == NULL ? NULL : pa->next;
				prev = prev->next;
			}
			else {
				prev->next = new ListNode(pa->val);
				prev = prev->next;
				prev->next = new ListNode(pb->val);
				pb = pb == NULL ? NULL : pb->next;
				pa = pa == NULL ? NULL : pa->next;
				prev = prev->next;
			}
		}
		while (pa != NULL) {
			prev->next = new ListNode(pa->val);
			pa = pa == NULL ? NULL : pa->next;
			prev = prev->next;
		}
		while (pb != NULL) {
			prev->next = new ListNode(pb->val);
			pb = pb == NULL ? NULL : pb->next;
			prev = prev->next;
		}
		prev->next = NULL;
	
		return dummy.next;
	}

};
int main234()
{
	ListNode head1(-1);
	ListNode head2(-1);
	ListNode head3(-1);
	ListNode *p1 = &head1;
	ListNode *p2 = &head2;
	ListNode *p3 = &head3;
	ListNode *pp1  = p1;
	ListNode *pp2  = p2;
	ListNode *pp3  = p3;

	int a[5] = { 1,2,4,5,9 };
	int b[5] = { 2,5,6,7,9 };
	for (int i = 0; i < 5; ++i) {
		p1->next = new ListNode(a[i]);
		p1 = p1->next;
	}
	for (int i = 0; i < 5; ++i)
	{
		p2->next = new ListNode(b[i]);
		p2 = p2->next;
	}
	p1->next = NULL;
	p2->next = NULL;

	Solution sol;
	p3 = sol.mergeTwoLists(pp1->next, pp2->next);
	
	ListNode *p4 = p3 ;
	while (p4!= NULL)
	{
		cout << p4->val << endl;
		p4 = p4 == NULL ? NULL : p4->next;
	}

	return 0;
}