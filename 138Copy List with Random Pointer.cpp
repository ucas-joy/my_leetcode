/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/

#include<iostream>
using namespace std;
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL)
			return head;
		// ��һ��,��������ÿ���������һ��copyNode(��������Ľ��)
		RandomListNode *nowNode = head;
		while (nowNode != NULL){
			RandomListNode *copyNode = new RandomListNode(nowNode->label);
			copyNode->random = nowNode->random;
			copyNode->next = nowNode->next;
			nowNode->next = copyNode;
			nowNode = nowNode->next->next;
		}
		/*�ڶ���:ȷ��NewList��ÿ���ڵ�,������������Random������ĸ�����Ϊ��һ���Ѿ�������NewList�ϵĽ�㶼������*/
		nowNode = head;
		while (nowNode != NULL) {
			if (nowNode->random != NULL) {
				nowNode->next->random = nowNode->random->next;
			}
			nowNode = nowNode->next->next;
		}
		/*����������ԭOldList��nextΪһ��ʼ��next���  ��ƴ��NewList��next����������Ӧ�ù�����next��� ��������������OldList���䣬ƴ��������NewList��
		 */
		RandomListNode *pHead = new RandomListNode(0);
		pHead->next = head;
		RandomListNode *newlist = pHead;

		nowNode = head;
		while (nowNode != NULL)
		{
			pHead->next = nowNode->next;
			nowNode->next = pHead->next->next;
			pHead = pHead->next;
			nowNode = nowNode->next;
		}
		return newlist->next;
	}
};