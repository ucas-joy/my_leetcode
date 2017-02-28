/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
[".Q..",  // Solution 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // Solution 2
"Q...",
"...Q",
".Q.."]
]
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<int> position(n, -1);//容器构建一维数组存储皇后的行、列位置，下标表示行，对应元素值表示列,并初始化
		searchSolution(position, n, 0);//搜索可行解,从第0行开始，放置第1个皇后，注意数组下标从“0”开始
		return result;
	}
private:
	vector<vector<string>> result;//存放可行解的容器，一个二维字符串数组
	void searchSolution(vector<int>& position, int n, int row)//寻找可行解
	{
		if (row == n)//row==n表示N个皇后都已经放置到合法位置，应存储可行解
		{
			vector<string> temp(n, string(n, '.'));//构建一个字符串数组存放输出解的形式，初始化为N*N的'.'矩阵
			for (int i = 0; i<n; i++){
				temp[i][position[i]] = 'Q';//将每一行皇后的列位置替换成'Q',第i个皇后位于第i-1行，第position[i-1]列
			}
			result.push_back(temp);//存储可行性解
		}
		else{
			position[row] = 0;//如果没有完毕，我们继续放置第row行的皇后，第row行的皇后可能的列位置为第0列至第N-1列
			while (position[row]<n)//从第0列开始遍历，直到找到“合法”的列位置
			{
				if (checkValid(position, n, row))//判断当前列位置position[row]是否合法
					searchSolution(position, n, row + 1);//若合法，则继续放置第row+1行的皇后
				position[row]++;//列位置增
			}
		}
	}
	//检验第row行放置的皇后的列位置是否合法，核心思想就是与前面的row-1行皇后的列位置进行比较
	bool checkValid(vector<int>& position, int n, int row){
		for (int i = 0; i<row; i++)//第row行皇后不能与前面的皇后处于同一列，同一斜线,（按行序放置已经避免处于同一行）
		{
			if (position[i] == position[row] || abs(position[i] - position[row]) == abs(i - row))
				return false;
		}
		return true;
	}

};
int main51()
{
	Solution sol;
	vector<vector<string>>res = sol.solveNQueens(4);
	cout << endl;
	return 0;
}
