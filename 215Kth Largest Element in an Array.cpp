/*
215. Kth Largest Element in an Array   QuestionEditorial Solution  My Submissions
Total Accepted: 86988
Total Submissions: 239016
Difficulty: Medium
Contributors: Admin
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		if (nums.size() == 0)
			return 0;
		priority_queue<int>q;
		for (int i = 0; i < nums.size(); ++i){
			q.push(nums[i]);
		}
		while (k > 1){
			q.pop();
			k--;
		}
		return q.top();
	}
};
int main()
{
	int a[6] = { 3, 2, 1, 5, 6, 4 }, k = 2;
	vector<int>b(a, a + 6);
	Solution sol;
	int t = sol.findKthLargest(b, k);
	cout << t << endl;
	return 0;
}