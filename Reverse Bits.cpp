/*
Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100),
return 964176192 (represented in binary as 00111001011110000010100101000000).

Follow up:
If this function is called many times, how would you optimize it?

Related problem: Reverse Integer
*/
#include <BaseTsd.h>
#include<stdint.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		if (n == 0) {
			return 0;
		}
		int t = 0;
		vector<int> tmp;
		while (n != 0) {
			t = n % 2;
			tmp.push_back(t);
			n = n / 2;
		}
		int j = 32 - tmp.size();
		for (int i = 0; i < j; ++i)
		{
			tmp.push_back(0);
		}
		reverse(tmp.begin(), tmp.end());
		uint32_t rev = 0;
		uint32_t mul = 1;
		for (int i = 0; i < 32; ++i) {
			rev = rev + tmp[i] * mul;
			mul = mul * 2;
		}
		return rev;
	}
};
int main() {
	uint32_t t = 43261596;
	Solution sol;
	uint32_t k = sol.reverseBits(t);
	cout << k << endl;
	return 0;
}