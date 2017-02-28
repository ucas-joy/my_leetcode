/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
[ 1,  5,  9],
[10, 11, 13],
[12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü n2.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int left = matrix[0][0];
		int right = matrix[n - 1][n - 1];
		while (left < right) {
			int mid = left + (right - left) / 2;
			int count = 0;
			for (int i = 0; i < n; ++i)
			{
				vector<int>&tmp = matrix[i];
				count += upper_bound(tmp.begin(), tmp.end(), mid) - tmp.begin();
			}

			if (count < k) {
				left = mid + 1;
			}
			else{
				right = mid;
			}
		}
		return left;
	}
};