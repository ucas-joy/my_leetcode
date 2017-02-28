
/*
Implement pow(x, n).

Subscribe to see which companies asked this question

pow(2, 3) = 8
*/

#include<iostream>
using namespace std;

class Solution {
public:
	/*double myPow(double x, int n) {
		if (n == 0)	return 1;
		if (n == 1) return x;
		if (n < 0){
			n = -n;
			x = 1.0 / x;
		}
		double ans =1 ;
		while (n){
			if (n & 1)  ans *= x;
			x = x *x;
			n = n / 2;
		}
		return ans;
	}*/

	double myPow(double x, int n) {
		if (n < 0) return 1 / power(x, -n);
		return power(x, n);
	}
	double power(double x, int n) {
		if (n == 0) return 1;
		double half = power(x, n / 2);
		if (n % 2 == 0) return half * half;
		return x * half * half;
	}
};

int main50()
{
	int a = 2;
	int b = 3;
	Solution sol;
	double c = sol.myPow(2, 10);
	cout << c << endl;
	return 0;
}