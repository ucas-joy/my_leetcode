/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty()) return 0;
		if (k >= prices.size()) return solveMaxProfit(prices);
		vector<int>g(k + 1, 0);
		vector<int>l(k + 1, 0);
		for (int i = 0; i < prices.size() - 1; ++i) {
			int diff = prices[i + 1] - prices[i];
			for (int j = k; j >= 1; --j) {
				l[j] = max(g[j - 1] + max(diff, 0), l[j] + diff);
				g[j] = max(g[j], l[j]);
			}
		}
		return g[k];

	}
	int solveMaxProfit(vector<int>&prices){
		int res = 0;
		for (int i = 1; i < prices.size(); ++i){
			if (prices[i] - prices[i - 1] > 0){
				res += prices[i] - prices[i - 1];
			}
		}
		return res;
	}
};
int main188()
{
	vector<int> a = { 2,5,7,1,4,3,1,3 };
	int k = 3;
	Solution sol;
	int t = sol.maxProfit(k,a);
	cout << t << endl;
	return 0;
}