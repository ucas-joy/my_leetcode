/*
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

Credits:
Special thanks to @amrsaqr for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

#include<iostream>
using namespace std;
class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int bit = 0;
		while (m != n)
		{
			m >>= 1;
			n >>= 1;
			bit++;
		}
		return m << bit;
	}
};
int main()
{
	int m = 5, n = 7;
	Solution sol;
	int t = sol.rangeBitwiseAnd(m, n);
	cout << t << endl;
	return 0; 

}