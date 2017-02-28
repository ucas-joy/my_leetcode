/*
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of 
being chosen.

Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using 
extra space?

Example:

// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
Subscribe to see which companies asked this question
*/


// Definition for singly-linked list.
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
	// @param head The linked list's head.
	//Note that the head is guaranteed to be not null, so it contains at least one node. 
	Solution(ListNode* head) :head_(head),n(0){
		while (head){
			n++;
			head = head->next;
		}
	}

//	Returns a random node's value. 
	int getRandom() {
		ListNode *root = head_;
		int m = n;
		while (rand() % (m--)) root = root->next;
		return root->val;
	}
private:
	ListNode *head_;
	int n;
};
/*
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(head);
* int param_1 = obj.getRandom();
*/