/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by 
connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool visited[1000][1000];
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size();
		if (m == 0){
			return 0;
		}
		int num = 0;
		int n = grid[0].size();
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				visited[i][j] = false;
			}
		}
		
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j){
				if (grid[i][j] == '1' && !visited[i][j]){
					num++;
					dfs(grid, m, n, i, j);
				}
			}
		}
		return num;
	}
	void dfs(vector<vector<char>>& grid, int m, int n, int x, int y){
		visited[x][y] = true;
		int dx[4] = { 1,0,-1,0 };
		int dy[4] = { 0,1,0,-1 };
		for (int i = 0; i < 4; ++i) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && xx < m && yy >= 0 && yy < n && grid[xx][yy] == '1' && !visited[xx][yy]){
				dfs(grid, m, n, xx, yy);
			}
		}
	}
};
int main200()
{
	/*
	11110
	11010
	11000
	00000
	*/
		Solution s;
		vector<vector<char> >vec{ { '1', '1', '1', '1','0' },{ '1', '1', '0', '1','0' },{ '1', '1', '0', '0','0' },{'0','0','0','0','0'} };
		int t = s.numIslands(vec);
		cout << t << endl;
		return 0;

}