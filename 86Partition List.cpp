/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.

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
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode dummy(-1);
		ListNode *p1 = head;
		ListNode *p2 = head;
		ListNode *phead = p1;
		ListNode *pre_p1 = NULL;
		ListNode *pre_p2 = NULL;
		while (p1 != NULL && p2 != NULL){
			 while(p1 != NULL &&p1->val < x)//��ͷ��ʼ�Ҵ���x��ֵ������ѭ����ʱ��p1ָ���������x��ֵ��
			 {
				pre_p1 = p1;
				p1 = p1 == NULL ? NULL : p1->next;
			 }
			 p2 = p1;
			 while (p2 != NULL && p2->val >= x)//��p1λ�ÿ�ʼ��С��x��ֵ����������ѭ����ʱ�� p2ָ�����С��x��ֵ,
			 {
				 pre_p2 = p2;
				 p2 = p2 == NULL ? NULL : p2->next;
			 }
			 //��p2ժ�������뵽pre_p1����
			 if (p2 != NULL){
				//��p2ժ����
				 pre_p2->next = p2->next == NULL ? NULL : p2->next;
				//��p2���뵽pre_p1���棬p1ǰ�档
				 if (pre_p1 == NULL){
					 p2->next = p1;
					 pre_p1 = p2;
					 phead = p2;
					 p2 = pre_p2->next;
				 }else
				 {
					 pre_p1->next = p2;
					 pre_p1 = p2;
					 p2->next = p1;
					 p2 = pre_p2->next;
				 }
				 
			 }
		}
		return phead;
	}
};
int main86()
{
	ListNode dummy(-1);
	ListNode *p1 = &dummy;
	ListNode *ph = &dummy;
	ListNode *phead = p1;
	//int a[6] = { 1,4,3,2,5,2 };
	int a[2] = { 2,1 };
	for (int i = 0; i < 2; ++i){
		p1->next = new ListNode(a[i]);
		p1 = p1->next;
	}
	Solution sol;
	ph = sol.partition(phead->next,2);
	while (ph != NULL)
	{
		cout << ph->val << endl;
		ph = ph->next == NULL ? NULL : ph->next;
	}
	return 0;
}