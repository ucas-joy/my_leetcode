/*
Counting Bits
given a non negative integer number num. For every numbers i in the range 0 ¡Ü i ¡Ü num calculate the number of 1's 
in their binary representation and return them as an array.

Example:
For num = 5 you should return [0,1,1,2,1,2].

Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)).
But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.

Hint:

You should make use of what you have produced already.
Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. And try to generate new range from previous.
Or does the odd/even status of the number help you in calculating the number of 1s?
Credits:
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int>vec(num + 1, 0);
		vec[0] = 0;
		for (int i = 1; i <= num; ++i) {
			vec[i] = vec[i / 2] + (i % 2);
		}
		return vec;
	}
};
int main123123()
{
	int i = 5;
	Solution sol;
	vector<int>res;
	res = sol.countBits(i);
	int j = 0;
	while (j < res.size())
	{
		cout << res[j] << endl;
		j++;
	}
	return 0;
}