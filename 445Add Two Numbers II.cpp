/*
You are given two linked lists representing two non-negative numbers. The most significant digit comes first and each of their nodes contain a single digit.
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7
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
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode dummy(-1);
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *phead1 = &dummy;
		ListNode *phead2 = &dummy;
		int len1 = 0;
		int len2 = 0;
		phead1 = p1;
		while (p1 != NULL){
			len1++;
			p1 = p1 == NULL ? NULL : p1->next;
		}
		phead2 = p2;
		while (p2 != NULL){
			len2++;
			p2 = p2 == NULL ? NULL : p2->next;
		}
		vector<int>v(len1 >= len2 ? len1 : len2);
		p1 = phead1;
		p2 = phead2;
		int len;
		int tmp_len ;
		if (len1 >= len2){
			len = len1 - len2;
			tmp_len = len;
			int i = 0;
			while (i < len){
				v[i] = p1->val;
				i++;
				p1 = p1->next;
			}
		}
		else{
			len = len2 - len1;
			tmp_len = len;
			int j = 0;
			while (j < len) {
				v[j] = p2->val;
				j++;
				p2 = p2->next;
			}
		}
		
		while (p1 != NULL && p2 != NULL)
		{
			v[tmp_len] = p1->val + p2->val;
			tmp_len++;
			p1 = p1 == NULL ? NULL : p1->next;
			p2 = p2 == NULL ? NULL : p2->next;
		}
		int flag = 0;
		for (int i = v.size()-1; i >= 0; --i)
		{
			v[i] = flag + v[i];
			flag = v[i] / 10;
			v[i] = v[i] % 10;
		}
		p1 = phead1;
		p2 = phead2;
		int k = 0;
		while(len1 >= len2 && p1!=NULL){
			p1->val = v[k++];
			p1 = p1 == NULL ? NULL : p1->next;
		}
		while(len1 < len2 && p2 != NULL){
			p2->val = v[k++];
			p2 = p2 == NULL ? NULL : p2->next;
		}

		if (len1 >= len2)
		{
			if (flag > 0)
			{
				ListNode *tmp = new ListNode(flag);
				tmp->next =phead1;
				phead1 = tmp;
			}
			return phead1;
		}
			
		if (len1 < len2)
		{
			if (flag > 0)
			{
				ListNode *tmp = new ListNode(flag);
				tmp->next = phead2;
				tmp->val = flag;
				phead2 = tmp;
			}
			return phead2;
		}
	}
};
int main445()
{
	ListNode dummy(-1);
	ListNode *p1 = &dummy;
	ListNode *p2 = &dummy;
	ListNode *ph1 = p1;
	ListNode *ph2 = p2;
	ListNode *ph3 = &dummy;
	/*int a[4] = { 7,2,4,3 };
	int b[3] = { 5,6,4 };
	for (int i = 0; i < 4; ++i)
	{
		p1->next = new ListNode(a[i]);
		p1 = p1->next;
	}
	for (int j = 0; j < 3; ++j)
	{
		p2->next = new ListNode(b[j]);
		p2 = p2->next;
	}*/
	int a[1] = { 5 };
	int b[1] = { 5 };
	for (int i = 0; i < 1; ++i)
	{
		p1->next = new ListNode(a[i]);
		p1 = p1->next;
	}
	for (int j = 0; j < 1; ++j)
	{
		p2->next = new ListNode(b[j]);
		p2 = p2->next;
	}
	Solution sol;
	ph3 = sol.addTwoNumbers(ph2->next, ph2->next);
	while (ph3 != NULL) {
		cout << ph3->val << endl;
		ph3 = ph3 == NULL ? NULL : ph3->next;
	}
	return 0;

}