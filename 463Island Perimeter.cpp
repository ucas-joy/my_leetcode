
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int islandPerimeter(vector<vector<int>>& grid) {
		if (grid.size() == 0)
			return 0;
		int dx[4] = { -1,0,1,0 };
		int dy[4] = { 0,-1,0,1 };
		int m = grid.size();
		int n = grid[0].size();
		int sum = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 1)
				{
					sum += 4;
					for (int k = 0; k < 4; ++k)
					{
						int ii = i + dx[k];
						int jj = j + dy[k];
						if (ii >= 0 && ii < m && jj >= 0 && jj < n && grid[ii][jj] == 1)
						{
							sum = sum - 1;
						}
					}
				}
			}
		}
		return sum;
	}
};

int main463()
{
//	vector<vector<int>> res = { {0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0} };
	vector<vector<int>> res = { {0,1} };
	Solution sol;
	int cnt = sol.islandPerimeter(res);
	cout << cnt << endl;
	return 0;
}
