/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
	int jump(vector<int>& nums) {
		int cnt = 0;
		int curRch = 0;
		int curMax = 0;
		for (int i = 0; i < nums.size(); ++i){
			if (curRch < i){
				cnt++;
				curRch = curMax;
			}
			curMax = max(curMax, nums[i] + i);
		}
		return cnt;
	}
};
int main()
{
	vector<int>a = { 2,3,1,1,4 };
	Solution sol;
	int t = sol.jump(a);
	cout << t << endl;
	return 0;
}