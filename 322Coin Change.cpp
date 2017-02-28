/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question

Show Tags

*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (amount < 0) return -1;
		vector<int> cnt(amount + 1, amount + 1);
		cnt[0] = 0;
		for (int i = 1; i <= amount; ++i) {
			for (int j = 0; j<coins.size(); ++j) {
				if (i >= coins[j]) {
					cnt[i] = min(cnt[i], cnt[i - coins[j]] + 1);
				}
			}
		}
		return (cnt[amount] == amount + 1) ? -1 : cnt[amount];
	}
};