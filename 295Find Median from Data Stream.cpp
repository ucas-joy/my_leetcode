/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. 
So the median is the mean of the two middle value.

Examples:
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3)
findMedian() -> 2
Credits:
Special thanks to @Louis1992 for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
/*
�󶥶��д洢��Ԫ�� �������� С�����е�Ԫ��
MaxHeap.size() == MinHeap.size()������ MaxHeap.size() == MinHeap.size() + 1
���У�

��MaxHeap.size() == MinHeap.size() + 1ʱ����λ������MaxHeap�ĶѶ�Ԫ��
��MaxHeap.size() == MinHeap.size()ʱ����λ������MaxHeap�Ѷ�Ԫ����MinHeap�Ѷ�Ԫ�صľ�ֵ
*/
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;
class MedianFinder {
public:

		priority_queue<int, vector<int>, greater<int>> min_heap;
		priority_queue<int, vector<int>, less<int>> max_heap;
	public:

		// Adds a number into the data structure.
		void addNum(int num) {
			if (min_heap.empty() || (num >= min_heap.top())) {
				min_heap.emplace(num);
			}
			else {
				max_heap.emplace(num);
			}

			if (min_heap.size() > max_heap.size() + 1) {
				max_heap.emplace(min_heap.top());
				min_heap.pop();
			}
			else if (max_heap.size() > min_heap.size()) {
				min_heap.emplace(max_heap.top());
				max_heap.pop();
			}
		}

		// Returns the median of current data stream
		double findMedian() {
			return min_heap.size() == max_heap.size()
				? 0.5 * (min_heap.top() + max_heap.top())
				: min_heap.top();
		}
	
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
class MedianFinder {
	priority_queue<int,vector<int>,greater<int>> min_heap;
	priority_queue<int, vector<int>, less<int>>max_heap;
public:
	void addNum(int num) {
		if (min_heap.empty() || (num >= min_heap.top())) {
			min_heap.emplace(num);
		}
		else {
			max_heap.emplace(num);
		}
		if (min_heap.size() > max_heap.size() + 1) {
			max_heap.emplace(min_heap.top());
			min_heap.pop();
		}
		else if (max_heap.size() > min_heap.size()) {
			min_heap.emplace(max_heap.top());
			max_heap.pop();
		}
	}
	double findMedian() {
		return min_heap.size() == max_heap.size()
			? 0.5 * (min_heap.top() + max_heap.top())
			: min_heap.top();
	}
};