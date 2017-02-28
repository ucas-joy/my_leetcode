
/*
class NumMatrix {
public:
	NumMatrix(vector<vector<int>> &matrix) :m(matrix){
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		vector<vector<int>>tmp = m;
		tmp = sum_col(tmp);
		int sum = 0;
		for (int i = row1; i <= row2; ++i){
			sum += tmp[i][col2] - tmp[i][col1-1];
		}
		return sum;

	}
	vector<vector<int>>sum_col(vector<vector<int>>&matrix){
		int row = matrix.size();
		int col = matrix[0].size();
		for (int i = 0; i < row; ++i){
			for (int j = 1; j < col; ++j){
				matrix[i][j] = matrix[i][j] + matrix[i][j - 1];
			}
		}
		return matrix;
	}
private:
	vector<vector<int>>&m;
};
*/
#include<vector>
#include<iostream>
using namespace std; 
class NumMatrix {
public:
	NumMatrix(vector<vector<int>> &matrix){
		int row = matrix.size();
		int col = matrix[0].size();
		dp = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));
		for (int i = 0; i < dp.size(); ++i) {
			dp[i][0] = 0;
		}
		for (int i = 0; i < dp[0].size(); ++i) {
			dp[0][i] = 0;
		}
		for (int i = 1; i < dp.size(); ++i) {
			for (int j = 1; j < dp[0].size(); ++j) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + matrix[i - 1][j - 1] - dp[i - 1][j - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		row1++;
		col1++;
		row2++;
		col2++;
		return dp[row2][col2] - dp[row1 - 1][col2] - dp[row2][col1 - 1] + dp[row1 - 1][col1 - 1];
	}
private:
	vector<vector<int>>dp;
};
int main304()
{
	vector<vector<int>> a = {
		{ 3,0,1,4,2 },
		{ 5,6,3,2,1 },
		{ 1,2,0,1,5 },
		{ 4,1,0,1,7 },
		{ 1,0,3,0,5 }
	};
	NumMatrix nummatrix(a);
	int t = nummatrix.sumRegion(2, 1, 4, 3);
	int t1 = nummatrix.sumRegion(1, 1, 2, 2);
	cout << "t1 = " << t1 << endl;
	cout << "t = " << t << endl;
	return 0;
} 