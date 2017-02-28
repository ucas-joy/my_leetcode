/*
Implement int sqrt(int x).

Compute and return the square root of x.

Subscribe to see which companies asked this question
*/
#include<iostream>
using namespace std;
class Solution {
public:
	int mySqrt(int x) {
		double begin = 0;
		double end = x;
		double result = 1;
		double mid = 0;
		while (abs(result - x) > 0.000001){
			mid = (begin + end) / 2;
			result = mid * mid;
			if (result > x){
				end = mid-1 ;
			}
			else{
				begin = mid+1 ;
			}
		}
		return (int)mid;
	}
};
int main()
{
	int i = 16;
	Solution sol;
	int t = sol.mySqrt(i);
	cout << t << endl;
	return 0;
}