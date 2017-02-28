/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note:
The numbers can be arbitrarily large and are non-negative.
Converting the input string to integer is NOT allowed.
You should NOT use internal library such as BigInteger.
Subscribe to see which companies asked this question
*/
#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string result;
		if (num1.length() == 0 || num2.length() == 0)
			return result;
		if ((num1.length() == 1 && num1[0] == '0') || (num2.length() == 1 && num2[0] == '0')){
			result += '0';
			return result;
		}
		int len1 = num1.length();
		int len2 = num2.length();
		reverse(num1.begin(),num1.end());
		reverse(num2.begin(), num2.end());
		int flag = 0;
		int tmp;
		vector<int>help(len1 + len2);
		int i, j;
		for (i = 0; i < len1; ++i){
			for (j = 0; j < len2; ++j) {
				tmp = (num1[i] - '0') *(num2[j] - '0');
				tmp = help[i + j] + tmp + flag;
				flag = tmp / 10;
				tmp = tmp % 10;
				help[i + j] = tmp;
			}
			if (flag != 0 && (i + j) < (len1+ len2)){
				help[i + j] = flag;
				flag = 0;
			}	
		}
		int k = len1 + len2 - 1;
		/*if (k == 1 && help[k-1] == 0){
			result += '0';
			return result;
		}*/
		while (help[k] == 0){
			k--;
		}
		for (; k >= 0; --k){
			result +=( help[k] + '0');
		}
		return result;
	}
};

int main()
{
	string a = "98";
	string b = "9";
	Solution sol;
	string c = sol.multiply(a, b);
	cout << c << endl;
	return 0;
}