/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size();
		if (m == 0)
			return 0;
		int n = grid[0].size();
		if (n == 0)
			return 0;
		vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
		if (m == 1 && n == 1){
			return grid[0][0];
		}
		dp[0][0] = grid[0][0];
		for (int i = 1; i < m; ++i){
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		}
		for (int i = 1; i < n; ++i){
			dp[0][i] = dp[0][i - 1] + grid[0][i];
		}
		for (int i = 1; i < m; ++i){
			for (int j = 1; j < n; ++j){
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}
		return dp[m - 1][n - 1];
	}
};
int main()
{
	//[[1,3,1],[1,5,1],[4,2,1]]
	vector<vector<int>> a = { 
		{1,3,1},
		{1,5,1},
		{4,2,1}
	};
	Solution sol;
	int t = sol.minPathSum(a);
	cout << t << endl;
	return 0;
}