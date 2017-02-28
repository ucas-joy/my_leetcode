/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>>result1;
		if (n == 0)
			return result1;
		vector<vector<int>>result(n,vector<int>(n));
		int row = n ;
		int column = n ;
		int top = 0, bot = row - 1, left = 0, right = column - 1;
		int t = 1;
		while (1)
		{
			for (int i = left; i <= right; ++i) result[top][i] = t++;
			top++;
			if (top > bot)	break;
			for (int i = top; i <= bot; ++i) result[i][right] = t++;
			right--;
			if (left > right) break;
			for (int i = right; i >= left; --i) result[bot][i] = t++;
			bot--;
			if (top > bot) break;
			for (int i = bot; i >= top; i--) result[i][left] = t++;
			left++;
			if (left > right) break;
		}
		return result;
	}
};

int main59()
{
	vector<vector<int>>tmp;
	Solution sol;
	tmp = sol.generateMatrix(3);
	int len = tmp.size();
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			cout << " " << tmp[i][j];
		}
		cout << endl;
	}
	return 0;
}