/*
Given two non-negative numbers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	string addStrings(string num1, string num2) {
		string result;
		if (num2.length() == 0)
			return num1;
		if (num1.length() == 0)
			return num2;
		int len1 = num1.length();
		int len2 = num2.length();
		int len = min(len1, len2);
		int flag = 0;
		int i, j;
		for (i = len1 - 1, j = len2 - 1; (i >= 0&&j >= 0); --i, --j) {
			int k = num1[i] - '0' + num2[j] - '0' + flag;
			flag = k / 10;
			k = k % 10;
			result += (k + '0');
		}
			int k = len1 - len - 1;
			while (k >= 0) {
				int tmp = 0;
				tmp += num1[k] - '0' + flag;			
				flag = tmp / 10;
				tmp = tmp % 10;
				result += tmp + '0';
				k--;
			}
			k = len2 - len - 1;
			while (k >= 0) {
				int tmp = 0;
				tmp += num2[k] - '0' + flag;
				flag = tmp / 10;
				tmp = tmp % 10;
				result += tmp + '0';
				k--;
			}
			if (flag == 1)
			{
				result += flag + '0';
			}
		reverse(result.begin(), result.end());
		return result;
	}
};
int main()
{
	string a = "9";
	string b = "99";
	string c;
	Solution sol;
	c = sol.addStrings(a, b);
	cout << c << endl;
}