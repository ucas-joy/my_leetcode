/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
[1,   4,  7, 11, 15],
[2,   5,  8, 12, 19],
[3,   6,  9, 16, 22],
[10, 13, 14, 17, 24],
[18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0)
			return false;
		int row = matrix.size();
		int column = matrix[0].size();
		int i = 0, j = column - 1;
		for (;i < row-1 && j >= 0;){
			if (matrix[i][j] == target)
				return true;
			if (matrix[i][j] > target){
				--j;
			}else{
				++i;
			}
		}
		return false;
	}
};
int main()
{
	int a[5][5] = {
		1, 4, 7, 11, 15,
		2, 5, 8, 12, 19,
		3, 6, 9, 16, 22,
		10, 13, 14, 17, 24,
		18, 21, 23, 26, 30
	};
	vector<vector<int>>b(5, vector<int>(5));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			b[i][j] = a[i][j];
		}
	}
	Solution sol;
	bool is = sol.searchMatrix(b, 5);
	cout << is << endl; 
	return 0;
}