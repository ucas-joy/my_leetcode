/*
Determine whether an integer is a palindrome. Do this without extra space.
*/
#include<iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x >= 0 && x < 10) {
			return true;
		}
		if (x < 0) {
			return false;
		}
		long long int T = 1;
		int tmp = x;
		while (x != 0) {
			x /= 10;
			T *= 10;
		}
		T = T / 10;
		int L = 10;
		int X = 1;
		while (L <= T) {
			int high = (tmp / T)%10;
			int low = (tmp % L)/X;
			if (high != low) {
				return false;
			}
			else{
				T = T / 10;
				L = L * 10;
				X = X * 10;
			}
		}
		return true;
	}
};
int main()
{
	int i = 1000000001;
	Solution sol;
	bool is;
	is = sol.isPalindrome(i);
	cout << is << endl;
	return 0;
}