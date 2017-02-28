/*
Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

Example:
Given matrix = [
[1,  0, 1],
[0, -2, 3]
]
k = 2
The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).

Note:
The rectangle inside the matrix must have an area > 0.
What if the number of rows is much larger than the number of columns?
Credits:
Special thanks to @fujiaozhu for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		if (matrix.size() == 0)
			return 0;
		int row = matrix.size(), col = matrix[0].size();
		int ans = INT_MIN;
		for (int i = 0; i < col; ++i)
		{
			vector<int>sum(row, 0);
			for (int j = i; j < col; ++j)
			{
				set<int>st{ 0 };
				int curSum = 0, curMax = INT_MIN;
				for (int x = 0; x < row; x++)
				{
					sum[x] += matrix[x][j];
					curSum += sum[x];
					auto it = st.lower_bound(curSum - k);
					if (it != st.end()) {
						curMax = max(curSum - *it, curMax);
					}
					st.insert(curSum);
				}
				ans = max(curMax, ans);
			}
		}
		return ans;
	}
};
/*
class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		if (matrix.size() == 0) return 0;
		int row = matrix.size(), col = matrix[0].size();
		int ans = INT_MIN;
		for (int i = 0; i < col; i++) //ап
		{
			vector<int> sum(row, 0);
			for (int j = i; j < col; j++) //ап
			{
				set<int> st{ 0 };
				int curSum = 0, curMax = INT_MIN;
				for (int x = 0; x < row; x++) //пп
				{
					sum[x] += matrix[x][j];
					curSum += sum[x];
					auto it = st.lower_bound(curSum - k);
					if (it != st.end()){
						curMax = max(curSum - *it, curMax);
					}
					st.insert(curSum);
				}
				ans = max(curMax, ans);
			}
		}
		return ans;
	}
};
*/