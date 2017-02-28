/*
Count the number of prime numbers less than a non-negative number, n.
*/


#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
class Solution {
public:
	int countPrimes(int n) {
		if (n == 0) return 0;
		vector<bool> tag(n - 1, true);
		tag[0] = false;
		int i, limit = sqrt(n);
		int count = 0;
		for (i = 2; i <= limit; ++i){
			for (int j = i * i; j < n; ++j){
				tag[j - 1] = false;
			}
		}
		for (int k = 0; k < n; ++k)
		{
			if (tag[k]) count++;
		}
		return count;
	}
};
int main()
{
	return 0;
}