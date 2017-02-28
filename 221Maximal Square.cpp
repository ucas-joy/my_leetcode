/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
Credits:
Special thanks to @Freezen for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return 0;
		int n = matrix[0].size();
		int maxArea = 0;
		vector<vector<int>>dp(m + 1, vector<int>(n + 1,0));
		for (int i = 0; i <n; ++i){
			if (matrix[0][i] == '1'){
				dp[0][i] = 1;
				maxArea = max(maxArea, dp[0][i]);
			}else{
				dp[0][i] = 0;
			}
		}
		for (int i = 0; i < m; ++i){
			if (matrix[i][0] == '1'){
				dp[i][0] = 1;
				maxArea = max(maxArea, dp[i][0]);
			}
			else{
				dp[i][0] = 0;
			}
		}
		for (int i = 1; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				if (matrix[i][j] == '1' &&matrix[i - 1][j] == '1' && matrix[i][j - 1] == '1' && matrix[i - 1][j - 1] == '1')
				{
					int edge = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) ;
					dp[i][j] = (sqrt(edge) + 1) *(sqrt(edge) + 1);
					maxArea = max(maxArea, dp[i][j]);
				}
				else if(matrix[i][j] == '1')
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = 0;
				}
				
			}
		}
		return maxArea;
	}
};
/*
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
*/
int main()
{
	vector<vector<char>> mat = {
		{'1','1','1','1'},
		{'1','1','1','1'},
		{'1','1','1','1'}
	};
	/*{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'} */
	Solution  sol;
	int t = sol.maximalSquare(mat);
	cout << t << endl;
	return 0;
}