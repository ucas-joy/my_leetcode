/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers.
Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.

Hint:

There is a simple O(n) solution to this problem.
You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
/*
class Solution {
public:
	long long integerBreak(long long n) {
		if (n == 2) return 1;
		if (n == 3) return 2;
		if (n == 4) return 4;
		if (n == 5) return 6;
		if (n == 6) return 9;
		return 3 * integerBreak(n - 3);
	}
};
*/
#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
	long long integerBreak(long long n) {
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		int i = (n - 4) / 3;
		int ret = 0;
		if ((n - 4) % 3 == 0){
			ret = 4 * pow(3, i);
		}
		else if ((n - 4) % 3 == 1){
			ret = 2 * pow(3, i + 1);
		}
		else{
			ret = pow(3, i + 2);
		}
		return ret;
	}
};
int main()
{
	Solution sol;
	int t = sol.integerBreak(10);
	cout << t << endl;
	return 0;
}
/*
解法一（纯dp）：

令dp[n]为n对应的最大积。

那么递推方程就是：dp[n] = max(i*dp[n - i], i*(n - i))(其中i从1到n - 1)。

边界 : dp[2] = 1;

时间复杂度：O(n2)

复制代码
class Solution {
public:
	int integerBreak(int n) {
		int dp[n];
		dp[1] = 1;
		dp[2] = 1;
		for (int i = 3; i <= n; i++) {
			dp[i] = -1;
			for (int j = 1; j<i; j++) {
				dp[i] = max(j*dp[i - j], max(dp[i], j*(i - j)));
			}
		}
		return dp[n];
	}
};
*/