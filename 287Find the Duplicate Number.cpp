/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. 
Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		if (nums.size() == 0)
			return -1;
		int fast = 0,slow = 0;
		int i = 0;
		int len = nums.size();
		while (1){
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast) break;
		}
		fast = 0;
		while (1){
			slow = nums[slow];
			fast = nums[fast];
			if (slow == fast)  break;
		}
		return slow;
	}
};
int main()
{
	int a[20] = { 18,13,14,17,9,19,7,17,4,6,17,5,11,10,2,15,8,12,16,17 };
	vector<int>b(a, a + 20);
	Solution sol;
	int t = sol.findDuplicate(b);
	cout << t << endl;
	return 0;
}