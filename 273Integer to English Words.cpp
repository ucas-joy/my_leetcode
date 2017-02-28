/*
Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Hint:

Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)
*/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
	string numberToWords(int num) {
		if (num == 0)
			return "Zero";
		string res;
		int cnt = 0;

		string unit[10] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };//1~9
		string mid[10] = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };//10~19
		string tens[10] = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };//20~90

		for (; num; num /= 1000, cnt++){
			int cur = num % 1000;
			if (cur == 0) continue;
			if (!res.empty()) res = " " + res;
			if (cnt == 1) res = "Thousand" + res;
			if (cnt == 2) res = "Million" + res;
			if (cnt == 3) res = "Billion" + res;
			int a[3] = { 0 };
			int idx = 2;
			while (cur) {//get every 3 digits in a[]
				a[idx--] = cur % 10;
				cur /= 10;
			}
			//cout<<"a[]: "<<a[0]<<a[1]<<a[2]<<endl;

			if (a[1] == 1) {
				if (!res.empty()) res = " " + res;
				res = mid[a[2]] + res;
				if (a[0] == 0) continue;
				res = unit[a[0] - 1] + " Hundred " + res;
				continue;
			}

			if (a[2] != 0) {
				if (!res.empty()) res = " " + res;
				res = unit[a[2] - 1] + res;
			}
			if (a[1] != 0) {
				if (!res.empty()) res = " " + res;
				res = tens[a[1] - 2] + res;
			}
			if (a[0] != 0) {
				if (!res.empty()) res = " " + res;
				res = unit[a[0] - 1] + " Hundred" + res;
			}
		}
		return res;
	}
};

int main()
{
	int a = 1234567;
	Solution sol;
	string res = sol.numberToWords(a);
	cout << res << endl;
	return 0;
}
 