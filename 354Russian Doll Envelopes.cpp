/*
You have a number of envelopes with widths and heights given as a pair of integers (w, h).
One envelope can fit into another if and only if both the width and height of one envelope is greater than the
width and height of the other envelope.

What is the maximum number of envelopes can you Russian doll? (put one inside other)

Example:
Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
/*
class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		vector<int> dp;
		sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
			if (a.first == b.first) return a.second > b.second;
			return a.first < b.first;
		});
		for (int i = 0; i < envelopes.size(); ++i) {
			auto it = lower_bound(dp.begin(), dp.end(), envelopes[i].second);
			if (it == dp.end()) dp.push_back(envelopes[i].second);
			else *it = envelopes[i].second;
		}
		return dp.size();
	}
};
*/
class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		int res = 0, n = envelopes.size();
		vector<int>dp(n, 1);
		sort(envelopes.begin(), envelopes.end());
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			res = max(res, dp[i]);
		}
		return res;
	}
};
int main354()
{
	vector<pair<int, int>> a = { {5,4},{6,4},{6,7},{2,3} };
	Solution sol;
	int t = sol.maxEnvelopes(a);
	cout << t << endl;
	return 0;
}