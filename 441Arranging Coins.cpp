/*
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
ก่
ก่ ก่
ก่ ก่

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
ก่
ก่ ก่
ก่ ก่ ก่
ก่ ก่

Because the 4th row is incomplete, we return 3.
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
using namespace std;
//class Solution {
//public:
//	int arrangeCoins(int n) {
//		if (n == 0)
//			return 0;
//		int i = 1;
//		while (1){
//			if (sum(i) <= n && sum(i + 1) > n){
//				return i;
//				break;
//			}
//			else{
//				++i;
//			}
//		}
//		return 0;
//	}
//	int sum(int n){
//		int sum = 0;
//		for (int i = 1; i <= n; ++i){
//			sum += i;
//		}
//		return sum;
//	}
//};
class Solution {
public:
	int arrangeCoins(int n) {
		return floor(-0.5 + sqrt((double)2 * n + 0.25));
	}
};

int main()
{
	int n = 10;
	Solution sol;
	int t = sol.arrangeCoins(n);
	cout << t << endl;
	return 0;
}