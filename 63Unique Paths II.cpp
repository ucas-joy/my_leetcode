/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		int m = obstacleGrid.size();
		if (m == 0)
			return 0;
		int n = obstacleGrid[0].size();
		if (n == 0)
			return 0;
		int dp[100][100] = { 0 };
		if (obstacleGrid[0][0] == 1) {
			dp[0][0] = 0;
			return dp[0][0];
		}
		if (obstacleGrid[0][0] == 0)
		{
			dp[0][0] = 1;
		}
		for (int i = 1; i < m; ++i) {
			if (dp[i - 1][0] == 0 || obstacleGrid[i][0] == 1) {
				dp[i][0] = 0;
			}
			else {
				dp[i][0] = 1;
			}
		}
		for (int i = 1; i < n; ++i) {
			if (dp[0][i - 1] == 0 || obstacleGrid[0][i] == 1) {
				dp[0][i] = 0;
			}
			else {
				dp[0][i] = 1;
			}
		}
		for (int i = 1; i < m; ++i) {
			for (int j = 1; j < n; ++j) {
				if (obstacleGrid[i][j] == 1) {
					dp[i][j] = 0;
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				}
			}
		}
		return dp[m - 1][n - 1];
	}
};
int main()
{
	vector<vector<int>>a = { {0},{1} };
	Solution sol;
	int t = sol.uniquePathsWithObstacles(a);
	cout << t << endl;
	return 0;
}