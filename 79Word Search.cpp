/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once.

For example,
Given board =

[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		if (board.size() == 0)
			return false;
		if (word.length() == 0)
			return true;
		int row = board.size();
		int column = board[0].size();
		bool found = false;
		vector<vector<bool>>visited(row, vector<bool>(column));
		for (int i = 0; i < row; ++i){
			for (int j = 0; j < column; ++j){
				found = search(board, visited, i, j, word, 0);
				if (found){
					return true;
				}
			}
		}
		return false;
	}
	bool search(vector<vector<char>>&board, vector<vector<bool>>&visited,int x , int y , string word, int k)
	{
		if (k == word.length())
			return true;
		if (x <0 || x > board.size()-1 || y< 0 || y> board[0].size()-1) return false;
		if (visited[x][y]) return false;
		if (board[x][y] != word[k]) return false;
		visited[x][y] = true;
		if (search(board, visited, x - 1, y, word, k + 1)|| search(board, visited, x + 1, y, word, k + 1)
			|| search(board, visited, x, y - 1, word, k + 1)|| search(board, visited, x, y + 1, word, k + 1)) 
			return true;
		/*if (search(board, visited, x + 1, y, word, k + 1))return true;
		if (search(board, visited, x , y-1, word, k + 1))return true;
		if (search(board, visited, x , y+1, word, k + 1))return true;*/
		visited[x][y] = false;
		return false;
	}
};
int main79()
{
	vector<vector<char>>vs(3,vector<char>(4));
	char a[4][4] = {
		'A','B','C','E',
		'S','F','C','S',
		'A','D','E','E'
	};
	for (int i = 0; i < 3; ++i){
		for (int j = 0; j < 4; ++j){
			vs[i][j] = a[i][j];
		}
	}
	string word = "ABCB";
	Solution sol;
	bool found = sol.exist(vs, word);
	cout << found << endl;
	return 0;
}