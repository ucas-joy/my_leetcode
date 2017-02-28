/*
166. Fraction to Recurring Decimal   QuestionEditorial Solution  My Submissions
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".
Hint:

No scary math, just apply elementary math knowledge. Still remember how to perform a long division?
Try a long division on 4/9, the repeating part is obvious. Now try 4/333. Do you see a pattern?
Be wary of edge cases! List out as many test cases as you can think of and test your code thoroughly.
Credits:
Special thanks to @Shangrila for adding this problem and creating all test cases.
*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		bool negative = (numerator < 0 && denominator>0) || (numerator > 0 && denominator < 0);
		using llong = long long;
		llong a = abs((llong)numerator);
		llong b = abs((llong)denominator);
		llong integerPart = a / b;
		llong decimalPart = a % b;

		if (decimalPart == 0)
		{
			return (negative ? "-" : "") + to_string(integerPart);
		}

		string decimalDigits;
		unordered_map<llong, llong> visitedRemainders;
		while (decimalPart != 0)
		{
			if (visitedRemainders.find(decimalPart) != visitedRemainders.end())  // ÎÞÏÞÑ­»·
			{
				decimalDigits.insert(visitedRemainders[decimalPart], "(");
				decimalDigits += ")";
				break;
			}

			llong digit = (decimalPart * 10) / b;
			decimalDigits += to_string(digit);
			visitedRemainders[decimalPart] = decimalDigits.size() - 1;

			decimalPart = (decimalPart * 10) % b;
		}
		return (negative ? "-" : "") + to_string(integerPart) + "." + decimalDigits;
	}
};