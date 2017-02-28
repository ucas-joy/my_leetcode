/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed,
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it
will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money
you can rob tonight without alerting the police.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;
class Solution {
public:
	int rob(vector<int> &num) {
		int n = num.size();
		if (n == 0)
			return 0;
		else if (n == 1)
			return num[0];
		else
		{
			vector<int> maxV(n, 0);
			maxV[0] = num[0];
			maxV[1] = max(num[0], num[1]);
			for (int i = 2; i < n; i++)
				maxV[i] = max(maxV[i - 2] + num[i], maxV[i - 1]);
			return maxV[n - 1];
		}
	}
};