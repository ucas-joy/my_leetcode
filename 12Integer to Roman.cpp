/*
12. Integer to Roman   QuestionEditorial Solution  My Submissions
Total Accepted: 81948
Total Submissions: 195325
Difficulty: Medium
Contributors: Admin
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	string intToRoman(int num) {
		string Roman[4][10] = {
			{ "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" },
			{ "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" },
			{ "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" },
			{ "", "M", "MM", "MMM" }
		};
		return Roman[3][num / 1000 % 10] + Roman[2][num / 100 % 10] + Roman[1][num / 10 % 10] + Roman[0][num % 10];

	}
};

int main()
{
	int num = 1012;
	Solution sol;
	string res = sol.intToRoman(num);
	cout << res << endl;
	return 0;
}