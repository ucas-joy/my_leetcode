/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/
#include<iostream>
using namespace std;
class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num == 1) {
			return true;
		}
		if(num <= 0){
			return false;
		}	
		while (num&&num % 4 == 0) {
				num = num / 4;
			}
		return num == 1;
	}
};
int main()
{
	int i = 0;
	bool is;
	Solution sol;
	is = sol.isPowerOfFour(i);
	cout << is << endl;
	return 0;
}