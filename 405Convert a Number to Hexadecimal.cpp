/*f
Given an integer, write an algorithm to convert it to hexadecimal. For negative integer, two¡¯s complement method is used.

Note:

All letters in hexadecimal (a-f) must be in lowercase.
The hexadecimal string must not contain extra leading 0s. If the number is zero, it is represented by a single zero character '0'; otherwise,
the first character in the hexadecimal string will not be the zero character.
The given number is guaranteed to fit within the range of a 32-bit signed integer.
You must not use any method provided by the library which converts/formats the number to hex directly.
Example 1:

Input:
26

Output:
"1a"
Example 2:

Input:
-1

Output:
"ffffffff"
Subscribe to see which companies asked this question
*/

#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
	string toHex(int num) {
			unsigned int n = num;
			string res = "";
			while (n)
			{
				int b = n % 16;
				res += b<10 ? char('0' + b) : char('a' + b - 10);
				n /= 16;
			}
			reverse(res.begin(), res.end());
			return res == "" ? "0" : res;
		}
};
int main()
{
	int n = -1;
	Solution sol;
	string a = sol.toHex(n);
	cout << a << endl;
	return 0;
}