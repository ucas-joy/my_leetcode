/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/
#include<vector>
#include<iostream>
using namespace std;
/*
class Solution {
public:
	//bool visited[1000][1000];
	bool flag = false;
	void solve(vector<vector<char>>& board) {
		int m = board.size();
		if (m == 0)
			return;
		int n = board[0].size();
		if (n == 0)
			return;
		vector<vector<bool>>visited(m, (vector<bool>(n, false)));
	
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j){
				if ((i == 0 || i == m - 1 || j == 0 || j == n - 1)&&board[i][j] == 'O' && !visited[i][j]){
					flag = false;
					dfs(board,visited ,m, n, i, j);
				}
			}
		}
		for (int i = 1; i < m-1; ++i) {
			for (int j = 1; j < n-1; ++j) {
				if (board[i][j] == 'O' && !visited[i][j]) {
					flag = true;
					dfs(board, visited,m, n, i, j);
				}
			}
		}
		return;
	}
	void  dfs(vector<vector<char>>&board,vector<vector<bool>>&visited ,int m , int n,int x, int y){
		int dx[4] = { 1,0,-1,0 };
		int dy[4] = { 0,1,0,-1 };
		visited[x][y] = true;
		if (flag == false) //遍历未被包围的
		{
			for (int i = 0; i < 4; ++i) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx >= 0 && xx < m && yy >= 0 && yy < n && !visited[xx][yy] && board[xx][yy] == 'O'){
					dfs(board,visited ,m, n, xx, yy);
				}
			}
		}
		else// 遍历包围的
		{
			board[x][y] = 'X';
			for (int i = 0; i < 4; ++i) {
				int xx = x + dx[i];
				int yy = y + dy[i];
				if (xx >= 1 && xx < m-1 && yy >= 1 && yy < n-1 && !visited[xx][yy] && board[xx][yy] == 'O') {
					dfs(board,visited ,m, n, xx, yy);
				}
			}
		}
	}
};
*/
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		int m = board.size();
		if (m == 0)
			return;
		int n = board[0].size();
		if (n == 0)
			return;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O'){
					dfs(board, m, n, i, j);
				}
			}
		}
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				if (board[i][j] == 'P') board[i][j] = 'O';
			}
		}

	}
	void dfs(vector<vector<char>>&board, int m, int n, int x, int y)
	{
		int dx[4] = { 1,0,-1,0 };
		int dy[4] = { 0,1,0,-1 };
		board[x][y] = 'P';
		for (int i = 0; i < 4; ++i)
		{
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx > 0 && xx < m  && yy > 0 && yy < n  && board[xx][yy] == 'O')
			{
				dfs(board, m, n, xx, yy);
			}
		}
	}
};
int main()
{
	vector<vector<char>>res = {
		/*{'X', 'X', 'X','X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X' }
		*/
		{'O','O'},
		{'O','O'}
	};
		//["XXXX","XOOX","XXOX","XOXX"


	Solution sol;
	sol.solve(res);
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;

}

/*

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) return;
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    if (board[i][j] == 'O') dfs(board, i , j);
                }
            }   
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>> &board, int x, int y) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> dir{{0,-1},{-1,0},{0,1},{1,0}};
        board[x][y] = '$';
        for (int i = 0; i < dir.size(); ++i) {
            int dx = x + dir[i][0], dy = y + dir[i][1];
            if (dx >= 0 && dx < m && dy > 0 && dy < n && board[dx][dy] == 'O') {
                dfs(board, dx, dy);
            }
        }
    }

};
*/