/*
A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		if (A.size() == 0) {
			return 0;
		}
		int Max = INT_MIN;
		int size = A.size();
		int start = 0;
		int i = 0;
		while (i < size)
		{
 			Max = max(Max, mult(A, start));
			start =  size - 1 - i;
			i++;
		}
		return Max;
	
	}
	int mult(vector<int>& B, int star) {
		int count = B.size();
		int tmp = 0;
		long long int f = 0;
		while (count--) {
			if (star >= B.size()) {
				star = 0;
			}
			f += B[star] * tmp;
			tmp++;
			star++;
		}
		return f;
	}
};
int main396()
{
	vector<int>A = { 4,3,2,6 };
	Solution sol;
	int j = sol.maxRotateFunction(A);
	cout << j << endl;
	return 0;
}