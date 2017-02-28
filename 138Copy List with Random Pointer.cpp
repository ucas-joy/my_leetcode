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
		// 第一步,在链表中每个结点后插入一个copyNode(拷贝链表的结点)
		RandomListNode *nowNode = head;
		while (nowNode != NULL){
			RandomListNode *copyNode = new RandomListNode(nowNode->label);
			copyNode->random = nowNode->random;
			copyNode->next = nowNode->next;
			nowNode->next = copyNode;
			nowNode = nowNode->next->next;
		}
		/*第二步:确定NewList的每个节点,真正关联到的Random结点是哪个，因为第一步已经把所有NewList上的结点都建立了*/
		nowNode = head;
		while (nowNode != NULL) {
			if (nowNode->random != NULL) {
				nowNode->next->random = nowNode->random->next;
			}
			nowNode = nowNode->next->next;
		}
		/*第三步：还原OldList的next为一开始的next结点  并拼接NewList的next到它真正所应该关联的next结点 即：保持老链表OldList不变，拼接新链表NewList！
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