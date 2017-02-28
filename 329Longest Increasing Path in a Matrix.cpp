/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
[9,9,4],
[6,6,8],
[2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
[3,4,5],
[3,2,6],
[2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
	
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)
			return 0;
		vector<vector<int>>cache(matrix.size());
		cache.assign(cache.size(), vector<int>(matrix[0].size()));
		int Max = 0;
		for (int i = 0; i < cache.size(); i++) {
			for (int j = 0; j < cache[0].size(); j++) {
				int len = dfs(cache, matrix, i, j);
				if (len > Max) {
					Max = len;
				}
			}
		}
		return Max;

	}
	int dfs(vector<vector<int>>&cache,vector<vector<int>>& matrix,int row , int col){
		if (cache[row][col]) return cache[row][col];
		int len = 1;
		if (row + 1 < matrix.size() && matrix[row + 1][col] > matrix[row][col]){
			len = max(len, 1 + dfs(cache, matrix, row+1, col));
		}
		if (row - 1 >= 0  && matrix[row - 1][col] > matrix[row][col]) {
			len = max(len, 1 + dfs(cache, matrix, row-1, col));
		}
		if (col + 1 < matrix[0].size() && matrix[row][col + 1] > matrix[row][col]) {
			len = max(len, 1 + dfs(cache, matrix, row, col+1));
		}
		if (col - 1 >= 0 && matrix[row][col - 1] > matrix[row][col]) {
			len = max(len, 1 + dfs(cache, matrix, row, col-1));
		}
		cache[row][col] = len;
		return len;
	}
};
int main329()
{
	Solution sol;
	vector<vector<int>>vec = { {9,9,4},{6,6,8},{2,1,1} };
	int t = sol.longestIncreasingPath(vec);
	cout << t << endl;
	return 0;
}


/*

int findLongest(vector<vector<int>>& cache, vector<vector<int>>& matrix, int row, int col) {
	if (cache[row][col]) return cache[row][col];
	int len = 1;
	if (row + 1 < matrix.size() && matrix[row + 1][col] > matrix[row][col]) {
		len = max(len, 1 + findLongest(cache, matrix, row + 1, col));
	}
	if (row - 1 >= 0 && matrix[row - 1][col] > matrix[row][col]) {
		len = max(len, 1 + findLongest(cache, matrix, row - 1, col));
	}
	if (col + 1 < matrix[0].size() && matrix[row][col + 1] > matrix[row][col]) {
		len = max(len, 1 + findLongest(cache, matrix, row, col + 1));
	}
	if (col - 1 >= 0 && matrix[row][col - 1] > matrix[row][col]) {
		len = max(len, 1 + findLongest(cache, matrix, row, col - 1));
	}
	cache[row][col] = len;
	return len;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
	if (matrix.size() == 0 || matrix[0].size() == 0) return 0;

	vector<vector<int>> cache(matrix.size());
	cache.assign(cache.size(), vector<int>(matrix[0].size()));
	int max = 0;
	for (int i = 0; i < cache.size(); i++) {
		for (int j = 0; j < cache[0].size(); j++) {
			int len = findLongest(cache, matrix, i, j);
			if (len > max) {
				max = len;
			}
		}
	}
	return max;
}
*/