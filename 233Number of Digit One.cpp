/*
Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

Hint:

Beware of overflow.
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<math.h>
using namespace std;

class Solution {
public:
	int countDigitOne(int n) {
		if (n < 1)
			return 0;
		int len = getLenOfNum(n);
		if (n == 1)
			return 1;
		int tmp1 = powerBaseOf10(len - 1);
		int first = n/ tmp1;
		int firstOneNum = first == 1 ? n %tmp1 + 1 : tmp1;
		int secondOneNum = first *(len - 1) *(tmp1 / 10);
		return firstOneNum + secondOneNum + countDigitOne(n % tmp1);
	}
	int getLenOfNum(int n){
		int len = 0;
		while (n != 0)
		{
			len++;
			n = n / 10;
		}
		return len;
	}
	int powerBaseOf10(int base){
		return int(pow(10, base));
	}
};
int main()
{
	int n = 5;
	Solution sol;
	int t = sol.countDigitOne(n);
	cout << t << endl;
	return 0;
}