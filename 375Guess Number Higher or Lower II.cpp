/*
We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.

However, when you guess a particular number x, and you guess wrong, you pay $x. You win the game when you guess the number I picked.

Example:

n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.
Given a particular n ¡Ý 1, find out how much money you need to have to guarantee a win.

Hint:

The best strategy to play the game is to minimize the maximum loss you could possibly face. Another strategy is to minimize the expected loss. Here, we are interested in the first scenario.
Take a small example (n = 3). What do you end up paying in the worst case?
Check out this article if you're still stuck.
The purely recursive implementation of minimax would be worthless for even a small n.
You MUST use dynamic programming.
As a follow-up, how would you modify your code to solve the problem of minimizing the expected loss, 
instead of the worst-case loss?
Credits:
Special thanks to @agave and @StefanPochmann for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
		for (int i = 2; i <= n; ++i)
		{
			for (int j = i - 1; j > 0; --j)
			{
				int global_min = INT_MAX;
				for (int k = j + 1; k < i; ++k) {
					int local_max = k + max(dp[j][k - 1], dp[k + 1][i]);
					global_min = min(global_min, local_max);
				}
				dp[j][i] = j + 1 == i ? j : global_min;
			}
		}
		return dp[1][n];
	}
};