/*
367. Valid Perfect Square   QuestionEditorial Solution  My Submissions
Total Accepted: 21034
Total Submissions: 57168
Difficulty: Medium
Contributors: Admin
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

#include<iostream>
using namespace std;
class Solution {
public:
	bool isPerfectSquare(int num) {
		if (num < 1) return false;
		if (num == 1) return true;
		int begin = 1, end = num / 2;
		while (begin <= end){
			long mid = (begin + end) / 2;
			if (mid *mid == num){
				return true;
			}else if(mid * mid < num)
			{
				begin = mid + 1;
			}else if(mid *mid > num)
			{
				end = mid - 1;
			}
		}
		return false;
	}
};

int main()
{
	int a = 16;
	Solution sol;
	bool is = sol.isPerfectSquare(a);
	cout << is << endl;
	return 0;
}