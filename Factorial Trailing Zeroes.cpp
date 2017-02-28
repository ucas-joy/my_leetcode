/*
Given an integer n, return the number of trailing zeroes in n!.
*/
#include<iostream>
using namespace  std;
class Solution {
public:
	int trailingZeroes(int n) {
		if (n < 5) {
			return 0;
		}
		int total = 0;
		while (n >= 5)
		{
			n /= 5;
			total += n;
		}
		return total;
	}
};

int main()
{
	int i = 5;
	Solution sol;
	int j;
	j = sol.trailingZeroes(i);
	cout << j << endl;
}
