/*Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated.
If you still see your function signature accepts a const char * argument,
please click the reload button  to reset your code definition.*/

#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	int myAtoi(string str) {
		if (str.length() == 0) {
			return 0;
		}
		if (str.length() == 1)
		{
			if (str[0] == '-' || str[0] == '+')
			{
				return 0;
			}
			return (str[0] - '0');
		}
		int len = str.length();
		int flag = 1;
		int i = 0;
		for (i=0 ; i < len &&isspace(str[i]); i++);
		if ((!isvalid(str[i])) &&(!isvalid(str[i+1]))) {
			return 0;
		}
		if (str[i] == '-') {
			flag = -1;
			i++;
		}
		if (str[i] == '+') {
			flag = 1;
			i++;
		}
		long long  num = 0;
		int index;
		for (i; str[i] == '0'; i++);
		if (!isvalid(str[i]))
		{
			return 0;
		}
		for (i; i < len; ++i)
		{
			if (!isvalid(str[i]))
			{
				break;
			}
			if (str[i] != '.') {
				num = num * 10;
				num = num + (str[i] - '0');
			}
			if (num > INT_MAX)
			{
				return flag == -1 ? INT_MIN : INT_MAX;
			}
			if (str[i] == '.')
			{
				index = i;

			}
		}
		if (str[i] == '.') {
			while (index + 1 < len)
			{
				num /= 10;
				++index;
			}
		}
		
		
		return num*flag;
	}
	bool isvalid(char &ch)
	{
		if (ch == '+' || ch == '-' || ch == ' ' || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		{
			return false;
		}
		return true;
	}
};
int main123()
{
	string s = "9223372036854775809";
	Solution sol;
	int i;
	i = double(sol.myAtoi(s));
	cout << i << endl;
	return 0;
}