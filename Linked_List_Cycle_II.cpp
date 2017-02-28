/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.
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
	ListNode *detectCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) {
			return NULL;
		}
		ListNode *slow = head;
		ListNode *fast = head;
		while (fast != NULL && fast->next != NULL ) {
			
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast)
			{
				ListNode *slow2 = head;
				while (slow2 != slow) {
					slow2 = slow2->next;
					slow = slow->next;
					
				}
				return slow2;
			}
		}
		return NULL;
	}
};