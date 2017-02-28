/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
*/
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/*class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode dummy(-1);
		ListNode *p1 = NULL;
		if (lists.size() == 0)
			return p1;
		if (lists.size() == 1)
			return lists[0];
		stack<ListNode*>st;
		vector<ListNode*>::iterator it;
		for (it = lists.begin(); it !=  lists.end();++it )
		{
			st.push(*it);
		}
		while (st.size() != 1)
		{
			ListNode *t1 = st.top();
			st.pop();
			ListNode *t2 = st.top();
			st.pop();
			ListNode *t3 = mergeTwoLists(t1, t2);
			st.push(t3);
		}
		return st.top();
	}
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
	ListNode* mergeLists(ListNode*l1, ListNode *l2){
		if (l1 == NULL && l2 == NULL)
			return NULL;
		if (l1 == NULL || l2 == NULL)
			return l1 == NULL ? l2 : l1;
		ListNode dummy(-1);
		ListNode *phead = &dummy;
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *tmp = &dummy;
		ListNode *head = &dummy;
		head = phead;
		while (p1 != NULL && p2 != NULL) {
			if (p1->val > p2->val) {
				tmp = p2;
				p2 = p2 == NULL ? NULL : p2->next;
				phead->next = tmp;
				phead = tmp;
			}
			else{
				tmp = p1;
				p1 = p1 == NULL ? NULL : p1->next;
				phead->next = tmp;
				phead = tmp;
			}
		}
		while (p1 != NULL) {
			phead->next = p1;
			phead = p1;
			p1 = p1 == NULL ? NULL : p1->next;
		}
		while (p2 != NULL) {
			phead->next = p2;
			phead = p2;
			p2 = p2 == NULL ? NULL : p2->next;
		}
		phead->next = NULL;
		return head->next;
	}
	
};*/
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		struct cmp {
			bool operator()(ListNode *a, ListNode *b)
			{
				return (a->val > b->val);
			}
		};
		priority_queue<ListNode*, vector<ListNode*>, cmp>minHeap;
		for (int i = 0; i < lists.size(); ++i){
			if (lists[i]) minHeap.push(lists[i]);
		}
		ListNode *head = NULL, *tail = NULL;
		while (!minHeap.empty())
		{
			ListNode *min = minHeap.top();
			minHeap.pop();
			if (!head)
			{
				head = tail = min;
			}else{
				tail->next = min;
				tail = min;
			}
			if (min->next) minHeap.push(min->next);
		}
		return head;
	}
};
int main23()
{
	ListNode *p1 = NULL;
	ListNode *p2 = NULL;
	ListNode *ph = NULL;
	vector<ListNode*>ls;
	ls.push_back(p1);
	ls.push_back(p2);
	Solution sol;
	ph = sol.mergeKLists(ls);
	return 0;
}