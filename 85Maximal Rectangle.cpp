/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
Subscribe to see which companies asked this question
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		vector<int>left(n, 0);
		vector<int>right(n, n);
		vector<int>height(n, 0);
		int MaxArea = 0;
		for (int i = 0; i < m; ++i) {
			int curLeft = 0, curRight = n;
			for (int j = 0; j < n; ++j){
				if (matrix[i][j] == '1'){
					left[j] = max(curLeft, left[j]);
				}
				else{
					left[j] = 0;
					curLeft = j + 1;
				}
			}
			for (int j = 0; j < n; ++j){
				if (matrix[i][j] == '1'){
					height[j]++;
				}
				else{
					height[j] = 0;
				}
			}
			for (int j = n - 1; j >= 0; --j){
				if (matrix[i][j] == '1'){
					right[j] = min(right[j], curRight);
				}
				else{
					right[j] = n;
					curRight = j;
				}
			}
			for (int i = 0; i < n; ++i) {
				MaxArea = max(MaxArea, (right[i] - left[i])*height[i]);
			}		
		}	
		return MaxArea;
	}
};
int main85()
{
	vector<vector<char>> a = { 
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','0','0','1','0'}
	};
	Solution sol;
	int t = sol.maximalRectangle(a);
	cout << t << endl;
	return 0;
}

