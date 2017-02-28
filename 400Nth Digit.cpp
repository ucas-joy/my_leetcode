/*
Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 
is a 0, which is part of the number 10.
*/
#include<iostream>
using namespace std;
class Solution {
public:
	int findNthDigit(int n) {
		if (n < 10) {
			return n;
		}
		n = n - 9;
		if (n % 2 == 0) {
			n = (10+ n % 10)/2 -1;
			return n;
		}
		if (n % 2 != 0) {
			n = (n / 10) - 1;
			return n;
		}
		return 0;
	}
};
int main400()
{
	int n = 11;
	Solution sol;
	int j = sol.findNthDigit(n);
	cout << j << endl;
	return 0;
}