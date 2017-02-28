/*
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches 
the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

Pacific ~   ~   ~   ~   ~
~  1   2   2   3  (5) *
~  3   2   3  (4) (4) *
~  2   4  (5)  3   1  *
~ (6) (7)  1   4   5  *
~ (5)  1   1   2   4  *
*   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef pair<int, int>P;
class Solution {
public:
	vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
		int m = matrix.size();
		if (m == 0)
			return{};
		int n = matrix[0].size();
		if (n == 0)
			return{};
		vector<vector<int>>pac(m, vector<int>(n, 0));
		vector<vector<int>>atl(m, vector<int>(n, 0));
		vector<pair<int, int>>ans;
		for (int i = 0; i < m; ++i){
			flow(i, 0, matrix, pac);
			flow(i, n - 1, matrix, atl);
		}
		for (int i = 0; i < n; ++i) {
			flow(0, i, matrix, pac);
			flow(m - 1, i, matrix, atl);
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (pac[i][j] == 1 && atl[i][j] == 1) ans.push_back({ i,j });
			}
		}
		return ans;
	}
	void flow(int i, int j, vector<vector<int>>&matrix, vector<vector<int>>&visited){
		if (visited[i][j] == 1) return;
		queue<P>q;
		q.push({ i,j });
		int m = matrix.size();
		int n = matrix[0].size();
		while (!q.empty()){
			P p = q.front();
			q.pop();
			int x = p.first;
			int y = p.second;
			if (visited[x][y] == 1) continue;
			visited[x][y] = 1;
			if (x > 0 && matrix[x - 1][y] >= matrix[x][y]){
				q.push({ x - 1,y });
			}
			if (y > 0 && matrix[x][y - 1] >= matrix[x][y]) {
				q.push({ x, y - 1 });
			}
			if (x + 1 < m && matrix[x + 1][y] >= matrix[x][y]) {
				q.push({ x + 1,y });
			}
			if (y + 1 < n && matrix[x][y + 1] >= matrix[x][y]) {
				q.push({ x,y + 1 });
			}
		}
	}
};
int main417()
{
	vector<vector<int>>vec = { {1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4} };
	Solution sol;
	vector<pair<int, int>>res = sol.pacificAtlantic(vec);
	return 0;
}