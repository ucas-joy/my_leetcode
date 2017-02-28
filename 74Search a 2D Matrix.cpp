/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
Given target = 3, return true.

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
		if (column == 0)
			return false;
		int i = row-1, j = 0;
		for (; (i >= 0)&&(j < column);){
			if (matrix[i][j] == target){
				return true;
			}else if(matrix[i][j] > target){
				i--;
			}else if(matrix[i][j] < target){
				j++;
			}
		}
		return false;
	}
};
int main74()
{
	int a[3][4] = {
		1, 3, 5, 7,
		10, 11, 16, 20,
		23, 30, 34, 50
	};
	vector<vector<int>>B;
	for (int i = 0; i < 3; i++){
		vector<int>A;
		for (int j = 0; j < 4; j++){
			A.push_back(a[i][j]);
		}
		B.push_back(A);
	}
	bool find;
	Solution sol;
	find = sol.searchMatrix(B, 3);
	cout << find << endl;
	return 0;
}