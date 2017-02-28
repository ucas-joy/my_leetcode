/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
1 [3  -1  -3] 5  3  6  7       3
1  3 [-1  -3  5] 3  6  7       5
1  3  -1 [-3  5  3] 6  7       5
1  3  -1  -3 [5  3  6] 7       6
1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note:
You may assume k is always valid, ie: 1 ¡Ü k ¡Ü input array's size for non-empty array.

Follow up:
Could you solve it in linear time?

Hint:

How about using a data structure such as deque (double-ended queue)?
The queue size need not be the same as the window¡¯s size.
Remove redundant elements and the queue should store only elements that need to be considered.
Subscribe to see which companies asked this question
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
/*class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		if (nums.size() == 0){
			return res;
		}
		int len = nums.size();
		int start = 0;
		int end = k;
		int M = INT_MIN;
		for (start = 0, end = k; end <= len;) {
			for (int i = start; i < end; ++i){
				M = max(M, nums[i]);
			}
			res.push_back(M);
			start++;
			end++;
			M = INT_MIN;
		}
		return res;
	}
};*/
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		vector<int> ans;
		for (int i = 0; i<nums.size(); i++) {
			if (!dq.empty() && dq.front() == i - k) dq.pop_front();
			while (!dq.empty() && nums[dq.back()] < nums[i])
				dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1) ans.push_back(nums[dq.front()]);
		}
		return ans;
	}
};
int main239()
{
	vector<int> a = { 1,3,-1,-3,5,3,6,7 };
	Solution sol;
	vector<int> b = sol.maxSlidingWindow(a,3);
	for (int i = 0; i < b.size(); ++i)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	return 0;

}