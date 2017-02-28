/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
using namespace std;
//class Solution {
//public:
//	vector<int> spiralOrder(vector<vector<int>>& matrix) {
//		vector<int> result;
//		if (matrix.size() == 0)
//			return result;
//		int row = matrix.size();
//		int column = matrix[0].size();
//		int i = 0, j = 0;
//		int t = 0;
//		int sum = row * column;
//		int count = 0;
//		while(1){   
//			while (j < row - t){
//				result.push_back(matrix[i][j]);
//				j++;
//				count++;
//				if (count == sum)
//					break;
//			}
//			if (count == sum)
//				break;
//			j--;
//			i++;
//			while(i < column - t){	
//				count++;
//				result.push_back(matrix[i][j]);
//				i++;
//				if (count == sum)
//					break;
//			}
//			if (count == sum)
//				break;
//			i--;
//			j--;
//			while (j >= t){
//				count++;
//				result.push_back(matrix[i][j]);
//				j--;
//				if (count == sum)
//					break;
//			}
//			if (count == sum)
//				break;
//			j++;
//			i--;
//			while (i >= t + 1){
//				count++;
//				result.push_back(matrix[i][j]);
//				i--;
//				if (count == sum)
//					break;
//			}
//			if (count == sum)
//				break;
//			t++;
//			i =  t;
//			j =  t;
//		}
//		return result;
//	}	
//};

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int>result;
		int row = matrix.size();
		if (row == 0)
			return result;
		int column = matrix[0].size();
		int top = 0, bot = row - 1, left = 0, right = column - 1;
		while (1)
		{
			for (int i = left; i <= right; i++) result.push_back(matrix[top][i]);
			top++;
			if (top > bot) break;
			for (int i = top; i <= bot; i++) result.push_back(matrix[i][right]);
			right--;
			if (left > right) break;
			for (int i = right; i >= left; i--) result.push_back(matrix[bot][i]);
			bot--;
			if (top > bot) break;
			for (int i = bot; i >= top; i--) result.push_back(matrix[i][left]);
			left++;
			if (left > right) break;
		}
		return result;
	}
};
int main59()
{
	int a[4][4] = {
		1, 2, 3,4,
		5, 6,7, 8,
		9,10,11,12,
		13,14,15,16
	};
	vector<vector<int>>B;
	for (int i = 0; i < 4; i++) {
		vector<int>A;
		for (int j = 0; j < 4; j++) {
			A.push_back(a[i][j]);
		}
		B.push_back(A);
	}
	vector<int> c;
	Solution sol;
	c = sol.spiralOrder(B);
	int len = c.size();
	int i = 0;
	while (i < len)
	{
		cout << c[i] << endl;
		i++; 
	}
	return 0;
}