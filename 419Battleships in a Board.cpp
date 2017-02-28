/*
Given an 2D board, count how many different battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s.
You may assume the following rules:

You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
Example:
X..X
...X
...X
In the above board there are 2 battleships.
Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
Follow up:
Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	bool used[1000][1000];
	void DFS(int x, int y, int n, int m, vector<vector<char>>&board) {
		int dx[4] = { 0,1,0,-1 };
		int dy[4] = { 1,0,-1,0 };
		used[x][y] = true;
		for (int i = 0; i < 4; ++i) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (xx >= 0 && yy >= 0 && xx < n && yy < m && board[xx][yy] == 'X' && !used[xx][yy]) {
				DFS(xx, yy, n, m, board);
			}
		}
	}
	int countBattleships(vector<vector<char>>& board) {
		int n = board.size();
		if (n == 0)
			return 0;
		int m = board[0].size();
		int cnt = 0;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				used[i][j] = false;
			}
		}
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == 'X' && !used[i][j]){
					DFS(i, j, n, m, board);
					cnt++;
				}
			}
		}
		return cnt;
	}
	
};
int main()
{
	Solution s;
	vector<vector<char> >vec{ { 'X', '.', '.', 'X' },{ '.', '.', '.', 'X' },{ '.', '.', '.', 'X' } };
	cout << s.countBattleships(vec);

	return 0;
}

/*
#include <iostream>  
#include <vector>  
using namespace std;

class Solution {
public:
	void dfs(vector<vector<char>>& board, int i, int j)
	{
		visited[i][j] = true;
		//left  
		if (i >= 0 && i < n && j - 1 >= 0 && j - 1 < m && !visited[i][j - 1] && board[i][j - 1] == 'X')
		{
			dfs(board, i, j - 1);
		}
		//right  
		if (i >= 0 && i < n && j + 1 >= 0 && j + 1 < m && !visited[i][j + 1] && board[i][j + 1] == 'X')
		{
			dfs(board, i, j + 1);
		}
		//top  
		if (i - 1 >= 0 && i - 1 < n && j >= 0 && j < m && !visited[i - 1][j] && board[i - 1][j] == 'X')
		{
			dfs(board, i - 1, j);
		}
		//bottom  
		if (i + 1 >= 0 && i + 1 < n && j >= 0 && j < m && !visited[i + 1][j] && board[i + 1][j] == 'X')
		{
			dfs(board, i + 1, j);
		}
	}

	int countBattleships(vector<vector<char>>& board) {
		n = board.size();
		m = board[0].size();
		num = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (board[i][j] == 'X' && !visited[i][j])
				{
					num++;
					dfs(board, i, j);
				}
			}
		}
		return num;
	}
private:
	int n;
	int m;
	int num;
	bool visited[1000][1000];
};

int main()
{
	Solution s;
	vector<vector<char> >vec{ { 'X', '.', '.', 'X' },{ '.', '.', '.', 'X' },{ '.', '.', '.', 'X' } };
	cout << s.countBattleships(vec);

	return 0;
}

#include <iostream>  
#include <vector>  
using namespace std;
class Solution {
public:
	void dfs(vector<vector<char>>&board, int i, int j){
		visited[i][j] = true;
		//left
		if (i >= 0 && i < n && j - 1 >= 0 && j - 1 < m && !visited[i][j - 1] && board[i][j-1] == 'X'){
			dfs(board, i, j - 1);
		}
		//right
		if (i >= 0 && i < n && j + 1 >= 0 && j + 1 < m && !visited[i][j + 1] && board[i][j + 1] == 'X'){
			dfs(board, i, j + 1);
		}
		//down
		if (i - 1 >= 0 && i - 1 < n && j >= 0 && j < m && !visited[i - 1][j] && board[i - 1][j] == 'X'){
			dfs(board, i - 1, j);
		}
		// top
		if (i + 1 >= 0 && i + 1 < n && j >= 0 && j < m && !visited[i + 1][j] && board[i + 1][j] == 'X'){
			dfs(board, i + 1, j);
		}
	}

	int countBattleships(vector<vector<char>>& board) {
		n = board.size();
		if (n == 0)
			return 0;
		m = board[0].size();
		num = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				visited[i][j] = false;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == 'X' && !visited[i][j]){
					num++;
					dfs(board, i, j);
				}
			}
		}
		return num;
	}
private:
	int m;
	int n;
	bool visited[1000][1000];
	int num;
};
int main()
{
	Solution s;
	vector<vector<char> >vec{ { 'X', '.', '.', 'X' },{ '.', '.', '.', 'X' },{ '.', '.', '.', 'X' } };
	cout << s.countBattleships(vec);

	return 0;
}
*/