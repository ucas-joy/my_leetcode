/*
Sort a linked list in O(n log n) time using constant space complexity
*/


#include<iostream>
#include<queue>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	struct cmp{
		bool operator()(ListNode *a, ListNode *b)
		{
			return (a->val > b->val);
		}
	};
	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		priority_queue<ListNode*,vector<ListNode*>, cmp>pq;
		ListNode dummy(-1);
		ListNode *p1 = head;
		while (p1 != NULL){
			pq.push(p1);
			p1 = p1 == NULL ? p1 : p1->next;
		}
		ListNode *phead = NULL;
		ListNode *ptail = NULL;
		while (!pq.empty()){
			ListNode *min = pq.top();
			pq.pop();
			if (phead == NULL){
				ptail = phead = min;
				
			}
			else
			{
				ptail->next = min;
				ptail = min;
			}
		}
		ptail->next = NULL;
		return phead;
	}
};

int main148()
{
	int a[6] = { 1,3,5,2,4,6 };
	ListNode dummy(-1);
	ListNode *p1 = &dummy;
	ListNode *ph = &dummy;
	ListNode *phead1 = p1;
	for (int i = 0; i < 6; ++i){
		p1->next = new ListNode(a[i]);
		p1 = p1->next;
	}
	p1 = NULL;
	Solution sol;
	phead1 = sol.sortList(phead1->next);
	while (phead1 != NULL)
	{
		cout << phead1->val << endl;
		phead1 = phead1 == NULL ? NULL : phead1->next;
	}
	return 0;
}