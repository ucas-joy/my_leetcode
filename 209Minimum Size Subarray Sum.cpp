/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ¡Ý s. 
If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int len = nums.size();
		int minL = len + 1;
		int high = 0, low = 0, sum = 0;
		while (high < len) {
			sum += nums[high];
			++high;
			while(sum >= s){
				minL = min(minL, high - low);
				sum -= nums[low];
				low++;
			}
		}
		if (minL == len + 1)
			return 0;
		return minL;
	}
};
int main()
{
	int a[6] = { 2,3,1,2,4,3 };
	vector<int>b(a, a + 6);
	Solution sol;
	int j = sol.minSubArrayLen(7,b);
	cout << j << endl;
	return 0;
}