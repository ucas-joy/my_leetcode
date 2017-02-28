/*
Sort a linked list using insertion sort.
*/



#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

//class Solution {
//public:
//	ListNode* insertionSortList(ListNode* head) {
//		if (head == NULL || head->next == NULL)
//			return head;
//		if (head->next->next == NULL)
//		{
//			if (head->val <= head->next->val)
//			{
//				return head;
//			}
//			else
//			{
//				ListNode *tmp = head;
//				head = head->next;
//				head->next = tmp;
//				tmp->next = NULL;
//				return head;
//			}
//
//		}
//		ListNode *phead = head;
//		ListNode *cur_i = NULL;
//		ListNode *cur_j = NULL;
//		ListNode *tmp = NULL;
//		ListNode *pre_cur_j = NULL;
//		ListNode *pre_head = NULL;
//		while (head != NULL)
//		{
//			cur_i = phead;
//			if (pre_head == NULL){
//				pre_cur_j = head;
//				head = head == NULL ? NULL : head->next;
//				cur_j = head;
//			}
//			else
//			{
//				pre_cur_j = pre_head;
//				cur_j = pre_head->next;
//			}
//			
//			while (cur_j != NULL && cur_j != cur_i && cur_j->val >= cur_i->val){
//				tmp = cur_i;
//				cur_i = cur_i->next;
//			}
//			
//			if (cur_j != cur_i && cur_j->val <= cur_i->val){
//				
//				if (pre_head == NULL)
//				{
//					pre_cur_j->next = cur_j->next == NULL ? NULL : cur_j->next;
//					cur_j->next = cur_i;
//					cur_i->next = pre_cur_j;
//
//
//				}
//				ListNode *cur = cur_j;
//				pre_cur_j->next = cur_j->next;
//				tmp->next = cur;
//				cur->next = cur_i;
//				head = pre_head->next;
//			}else
//			{
//				pre_head = head;
//				head = head->next == NULL ? NULL : head->next;
//			}
//			
//		}
//		return phead;
//	}
//};
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL && head->next == NULL)
			return head;
		vector<ListNode*>list_vec;
		while (head != NULL){
			list_vec.push_back(head);
			head = head->next == NULL ? NULL : head->next;
		}
		ListNode* phead = NULL;
		ListNode *ptail = NULL;
		phead = ptail;
		int i, j;
		for ( i = 1; i < list_vec.size(); ++i){
			ListNode *tmp = list_vec[i];
		    j = i - 1;
			while (j >= 0 && list_vec[j]->val > tmp->val)
			{
				list_vec[j + 1] = list_vec[j];
				j--;
			}
			list_vec[j + 1] = tmp;
		}
		for (int k = 0; k < list_vec.size(); ++k){
			ListNode *node = list_vec[k];
			if (!phead){
				phead = ptail = node;
			}else{
				ptail->next = node;
				ptail = node;
			}
		}
		ptail->next = NULL;
		return phead;

	}
};
int main147()
{
	//int a[6] = { 1,3,5,2,4,6 };
	int a[3] = { 3,2,4 };
	ListNode dummy(-1);
	ListNode *p1 = &dummy;
	ListNode *ph = &dummy;
	ListNode *phead1 = p1;
	for (int i = 0; i < 3; ++i) {
		p1->next = new ListNode(a[i]);
		p1 = p1->next;
	}
	p1 = NULL;
	Solution sol;
	ph = sol.insertionSortList(phead1->next);
	while (ph != NULL)
	{
		cout << ph->val << endl;
		ph = ph == NULL ? NULL : ph->next;
	}
	return 0;
}

/*
insertionSort(A, N)
{
for i ´Ó 1 µ½ N - 1{
v = A[i]
j = i - 1
while (j >= 0 && A[j] > v) {
A[j + 1] = A[j]
j--;
}
A[j + 1] = v
}
}
*/
