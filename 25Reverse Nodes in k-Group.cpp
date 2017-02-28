/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Subscribe to see which companies asked this question
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
	int getlistlen(ListNode *head){
		int len = 0;
		while (head){
			head = head == NULL ? NULL : head->next;
			++len;
		}
		return len;
	}
	ListNode *addHead(ListNode *head, ListNode *node) {
		node->next = head;
		return node;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		int len = getlistlen(head);
		ListNode dummy(-1);
		ListNode *pnode = &dummy;
		while (len >= k) {
			ListNode *phead = NULL;//��ʱͷ���
			for (int i = 0; i < k; i++) //ͷ�巨����ÿ��ժȡһ�����嵽pheadǰ�棬����� phead����ָ��ͷ��㡣
			{
				ListNode *ptmpnode = head;
				head = head->next;
				phead = addHead(phead, ptmpnode);
			}
			pnode->next = phead; // �ĺ����
			while (pnode->next) { // �ҵ�ĩβ
				pnode = pnode->next;
			}

			len = len - k;
		}
		pnode->next = head;
		return dummy.next;
	}
};
int main()
{
}

