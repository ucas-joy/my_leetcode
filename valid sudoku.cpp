/*
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int rowvaild[10] = { 0 };
		int colvaild[9][10] = { 0 };
		int subboard[9][10] = { 0 };
		for (int i = 0; i < 9; ++i) {
			memset(rowvaild, 0, sizeof(rowvaild));
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					if (!isvaild(rowvaild, board[i][j] - '0') || !isvaild(colvaild[j], board[i][j] - '0') || !isvaild(subboard[i / 3 * 3 + j / 3], board[i][j] - '0')) {
						return false;
					}
				}
				return true;
			}
		}
	}
	bool isvaild(int vaz[], int val){
		if (vaz[val] == 1) {
			return false;
		}
		else
		{
			vaz[val] = 1;
			return true;
		}
	}
};