/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?

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
#include<stack>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL) {
			return false;
		}
		stack<int> P;
		ListNode *pa = head;
		while (pa != NULL) {
			P.push(pa->val);
			pa = pa == NULL ? NULL : pa->next;
		}
		pa = head;
		while (pa != NULL) {
			if (P.top() != pa->val) {
				return false;
			}
			else
			{
				P.pop();
				pa = pa == NULL ? NULL : pa->next;
			}
		}
		return true;
	}
};

int main33333()
{
	ListNode head1(-1);
	ListNode *p = &head1;
	ListNode *pp1 = p;
	int a[6] = { 1,2,3,2,2,1 };
	for (int i = 0; i < 6; ++i) {
		p->next = new ListNode(a[i]);
		p = p->next;
	}
	p->next = NULL;
	Solution sol;
	bool is;
	is = sol.isPalindrome(pp1->next);
	cout << is << endl;
	return 0;
}