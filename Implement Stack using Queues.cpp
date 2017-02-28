/*Implement the following operations of a stack using queues.

push(x) --Push element x onto stack.
pop() --Removes the element on top of the stack.
top() --Get the top element.
empty() --Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek / pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively.You may simulate a queue by using a list or deque(double - ended queue),
as long as you use only standard operations of a queue.
You may assume that all operations are valid(for example, no pop or top operations will be called on an empty stack).
Update(2015 - 06 - 11) :
	The class name of the Java function had been updated to MyStack instead of Stack.

	*/

#include<iostream>
#include<queue>
using namespace std;
class Stack {
public:
	// Push element x onto stack.
	queue<int> q1;
	queue<int> q2;
	void push(int x) {
		if (q1.empty()) {
			q1.push(x);
			while (!q2.empty()) {
				int tmp = q2.front();
				q2.pop();
				q1.push(tmp);
			}
		}
		if (q2.empty()) {
			q2.push(x);
			while (!q1.empty()) {
				int tmp = q1.front();
				q1.pop();
				q2.push(tmp);
			}
		}
	}

	// Removes the element on top of the stack.
	void pop() {
		if (!q1.empty())
		{
			q1.pop();
		}
		if (!q2.empty())
		{
			q2.pop();
		}

	}

	// Get the top element.
	int top() {
		if (!q1.empty())
		{
			return q1.front();
		}
		if (!q2.empty())
		{
			return q2.front();
		}
	}

	// Return whether the stack is empty.
	bool empty() {
		return (q1.empty() && q2.empty());
	}
};