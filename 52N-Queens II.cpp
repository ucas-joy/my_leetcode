/*
Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.



Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int totalNQueens(int n) {
		if (n < 1)
			return 0;
		vector<int>record(n, 0); // record[i] = j . 表示第（i,j）位置上有皇后
		return process(0, record, n);
	}
	int process(int i, vector<int>&record, int n) {
		if (i == n) {
			return 1;
		}
		int res = 0;
		for (int j = 0; j < n; ++j) {
			if (isValid(record, i, j)) {
				record[i] = j;
				res += process(i + 1, record, n);
			}
		}
		return res;
	}
	bool isValid(vector<int>&record, int i, int j) {
		for (int k = 0; k < i; ++k) {
			if (j == record[k] || abs(record[k] - j) == abs(i - k)) {
				return false;
			}
		}
		return true;
	}
};
int main52()
{
	Solution sol;
	int t = sol.totalNQueens(2);
	cout << t << endl;
	return 0; 
}

