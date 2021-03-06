/*
A sequence of number is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
using namespace std;
/*普通解法
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int len = A.size();
		if (len < 3)
			return 0;
		vector<int>minus;
		for (int i = 1; i < len; i++)
		{
			minus.push_back(A[i] - A[i - 1]);
		}
		long long int count = 0;
		int same_count = 1;
		int len1 = minus.size();
		int tmp = minus[0];
		for (int i = 1; i < len1; ++i){
			while (i < len1 && tmp == minus[i]){
				same_count++;
				i++;
			}
			if (same_count >= 2){
				long long int time = same_count *(same_count - 1);
				time = time / 2;
				count = count + time;
			}
			if (i < len1 && tmp != minus[i]){
				same_count = 1;
				tmp = minus[i];
			}
		}
		return count;
	}
	
	
};*/
// dp解法
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int len = A.size();
		if (len < 3)
			return 0;
		vector<int>dp(len, 0);
		if (A[2] - A[1] == A[1] - A[0]) dp[2] = 1;
		int result = dp[2];
		for (int i = 3; i < len; ++i)
		{
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
				dp[i] = dp[i - 1] + 1;
			result += dp[i];
		}
		return result;
	}
};
int main()
{
	//vector<int>a = { 1,1,2,5,7 };
	//vector<int> a = { 1,2,3,4 };
	//vector<int> a = { 1,3,5,7,9 };
	vector<int> a = { 0,0,0,0,1,1,1,1,1,2,2,2 };
	Solution sol;
	int t = sol.numberOfArithmeticSlices(a);
	cout << t << endl;
	return 0;
}

/*
class Solution {
public:
	int numberOfArithmeticSlices(vector<int>& A) {
		int n = A.size();
		if (n < 3) return 0;
		vector<int> dp(n, 0); // dp[i] means the number of arithmetic slices ending with A[i]
		if (A[2] - A[1] == A[1] - A[0]) dp[2] = 1; // if the first three numbers are arithmetic or not
		int result = dp[2];
		for (int i = 3; i < n; ++i) {
			// if A[i-2], A[i-1], A[i] are arithmetic, then the number of arithmetic slices ending with A[i] (dp[i])
			// equals to:
			//      the number of arithmetic slices ending with A[i-1] (dp[i-1], all these arithmetic slices appending A[i] are also arithmetic)
			//      +
			//      A[i-2], A[i-1], A[i] (a brand new arithmetic slice)
			// it is how dp[i] = dp[i-1] + 1 comes
			if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
				dp[i] = dp[i - 1] + 1;
			result += dp[i]; // accumulate all valid slices
		}
		return result;
	}
};
*/