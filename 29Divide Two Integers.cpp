/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.

Subscribe to see which companies asked this question
*/
#include<iostream>
using namespace std;

class Solution {
public:
		int divide(int dividend, int divisor) {
			if (!divisor || (dividend == INT_MIN && divisor == -1))
				return INT_MAX;
			bool sign = (dividend<0) ^ (divisor<0);
			long long dvd = labs(dividend);
			long long dvs = labs(divisor);
			int res = 0;
			while (dvd >= dvs)
			{
				long long tmp = dvs, multiple = 1;
				while (dvd >= (tmp << 1))
				{
					tmp <<= 1;
					multiple <<= 1;
				}
				dvd -= tmp;
				res += multiple;
			}
			return sign ? -res : res;


		}
	};



int main()
{
	int a = 20, b = 9;
	Solution sol;
	int c = sol.divide(a, b);
	cout << c << endl;
	return 0;
}