/*
Given a non-empty integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
Subscribe to see which companies asked this question

Show Tags
Show Similar Problems
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minMoves2(vector<int>& nums) {
		if (nums.size() <= 1)
			return 0;
		sort(nums.begin(), nums.end());
		int len = nums.size();
		int mid = len / 2;
		int moves = 0;
		for (int i = 0; i < len; ++i)
		{
			moves += abs(nums[mid] - nums[i]);
		}
		return moves;
	}
};
int main()
{
	vector<int> a = { 1,2,3 };
	Solution sol;
	int t = sol.minMoves2(a);
	cout << t << endl;
	return 0;
}