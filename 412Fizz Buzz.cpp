/*
Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output ¡°Fizz¡± instead of the number and for the multiples of five output ¡°Buzz¡±.
For numbers which are multiples of both three and five output ¡°FizzBuzz¡±.

Example:

n = 15,

Return:
[
"1",
"2",
"Fizz",
"4",
"Buzz",
"Fizz",
"7",
"8",
"Fizz",
"Buzz",
"11",
"Fizz",
"13",
"14",
"FizzBuzz"
]
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string>res;
		if (n == 0)
			return res;
		for (int i = 1; i <= n; ++i)
		{
			string result;
			if (i % 3 == 0 && i % 5 == 0){
				result = "FizzBuzz";
				res.push_back(result);
			}
			else if(i % 3 == 0 && i % 5 != 0)
			{
				result = "Fizz";
				res.push_back(result);
			}
			else if (i % 3 != 0 && i % 5 == 0)
			{
				result = "Buzz";
				res.push_back(result);
			}else
			{
				result = to_string(i);
				res.push_back(result);
			}
		}
		return res;
	}
};
int main()
{
	int n = 15;
	Solution sol;
	vector<string>s = sol.fizzBuzz(n);
	for (int i = 0; i < s.size(); ++i)
	{
		cout << s[i] << endl;
	}
	return 0;

}