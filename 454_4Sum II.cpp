/*
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ¡Ü N ¡Ü 500. All integers are in the range of -228 to 228 - 1 and 
the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int lenA = A.size();
		if (lenA == 0)
			return 0;
		vector<int>AB(lenA *lenA);
		for (int i = 0; i < lenA; ++i){
			for (int j = 0; j < lenA; ++j){
				AB[i * lenA + j] = A[i] + B[j];
			}
		}
		sort(AB.begin(), AB.end());
		long long cnt = 0;
		for (int i = 0; i < lenA; ++i) {
			for (int j = 0; j < lenA; ++j){
				int cd = -(C[i] + D[j]);
				cnt += upper_bound(AB.begin(), AB.end(), cd) - lower_bound(AB.begin(), AB.end(), cd);
			}
		}
		return cnt;
	}
};

int main()
{
	/*
	A = [ 1, 2]
	B = [-2,-1]
	C = [-1, 2]
	D = [ 0, 2]
	*/
	vector<int>A = { 1,2 };
	vector<int>B = { -2,-1 };
	vector<int>C = { -1,2 };
	vector<int>D = { 0,2 };
	Solution sol;
	int cnt = sol.fourSumCount(A, B, C, D);
	cout << cnt << endl;
	return 0;
}