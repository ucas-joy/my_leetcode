/*
Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. 
For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ¡Ü 100, 0 < n ¡Ü 106, 0 < primes[i] < 1000.

Credits:
Special thanks to @dietpepsi for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_map>
using namespace std;
class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		if (n <= 0){
			return 0;
		}
		if (n == 1){
			return 1;
		}
		int *Ugly = new int[n];
		Ugly[0] = 1;
		int i;
		vector<int*>p(primes.size());
		for (i = 0; i < primes.size(); ++i)
		{
			p[i] = Ugly;
		}
		int pNextUglyIndex =1;
		while (pNextUglyIndex < n){
			int m = Min(p,primes);
			Ugly[pNextUglyIndex] = m;
			++pNextUglyIndex;
			for (i = 0; i < primes.size(); ++i){
				while (*p[i] * primes[i] <= Ugly[pNextUglyIndex-1]){
					{*p[i]++; }
				}
			}
		}
		int nUgly = Ugly[pNextUglyIndex-1];
		delete Ugly;
		return nUgly;
	}
	int Min(vector<int*>p,vector<int>&prime){
		int M =( *p[0] )* prime[0];
		for (int i = 1; i < p.size(); ++i){
			M = min(M, (*p[i])* prime[i]);
		}
		return M;
	}
};

int main313()
{
	int a[3] = { 2,3,5 };
	vector<int>b(a, a + 3);
	Solution sol;
	int t = sol.nthSuperUglyNumber(4, b);
	cout << t << endl;
	return 0;
}