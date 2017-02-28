
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		int  rows = board.size();
		if (rows == 0)
			return;
		int colums = board[0].size();
		if (colums == 0)
			return;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < colums; ++j) {
				int sum = getNeighbor(board, rows, colums, i, j);
				if (board[i][j] == 1){
					if (sum > 3 || sum < 2){
						board[i][j] = 0;
					}

				}
				else{
					if (sum == 3)
						board[i][j] =1;
				}			 
			}
		}
	}
private:
	int getNeighbor(vector<vector<int>>& board, int rows, int colums, int x, int y){
		int sum = 0;
		for (int i = x - 1; i < x + 2; ++i){
			for (int j = y - 1; j < y + 2; ++j){
				if (i == x && j == y){
					continue;
				}
				if (i >= 0 && i < rows && y >= 0 && y < colums && (board[i][j] == 1))
					sum++;
			}
		}
		return sum;
	}
};

/*
ac ДњТы
class Solution
{
public:
void gameOfLife(vector<vector<int>>& board)
{
int rows=board.size();
if(rows==0)
return ;
int colums=board[0].size();
if(colums==0)
return ;
for(int i=0; i<rows; ++i)
{
for(int j=0; j<colums; ++j)
{
int sum=getNeighbor(board,rows,colums,i,j);
if(sum==2)
continue;
else if(sum==3)
board[i][j]=board[i][j]==0?3:1;
else
board[i][j]=board[i][j]==1?2:0;
}
}
for(int i=0;i<rows;++i)
{
for(int j=0;j<colums;++j)
board[i][j]%=2;
}


}
private:
int getNeighbor(vector<vector<int>>& board,int rows,int colums,int x,int y)
{
int sum=0;
for(int i=x-1; i<x+2; ++i)
{
for(int j=y-1; j<y+2; ++j)
{
if(i==x&&j==y)
continue;
if(i>=0&&i<rows&&j>=0&&j<colums&&(board[i][j]==1||board[i][j]==2))
++sum;
}
}
return sum;
}
};
*/