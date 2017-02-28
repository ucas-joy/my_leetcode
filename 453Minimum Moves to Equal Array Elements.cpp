/*
Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, 
where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int minMoves(vector<int>& nums) {
		int minindex = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			minindex = nums[i] < nums[minindex] ? i : minindex;
		}
		swap(nums[minindex], nums[0]);
		int moves = 0;
		for (int i = 1; i < nums.size(); ++i)
		{
			moves += nums[i] - nums[0];
		}
		return moves;
	}
};