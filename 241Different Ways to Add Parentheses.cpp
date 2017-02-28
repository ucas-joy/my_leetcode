/*
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators.
The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		vector<int>res;
		for (int i = 0; i < input.size(); ++i){
			if (input[i] == '+' || input[i] == '-' || input[i] == '*'){
				vector<int> left = diffWaysToCompute(input.substr(0, i));
				vector<int> right = diffWaysToCompute(input.substr(i + 1));
				for (int j = 0; j < left.size(); ++j){
					for (int k = 0; k < right.size(); ++k){
						if (input[i] == '+'){
							res.push_back(left[j] + right[k]);
						}
						else if (input[i] == '-'){
							res.push_back(left[j] - right[k]);
						}
						else{
							res.push_back(left[j] * right[k]);
						}
					}
				}
			}
		}
		if (res.empty()){
			res.push_back(atoi(input.c_str()));
		}
		return res;
	}
};
int main241()
{
	vector<int> s;
	Solution sol;
	string s1 = "2*3-4*5";
	s = sol.diffWaysToCompute(s1);
	int i = 0;
	while (i < s.size())
	{
		cout << s[i] << endl;
		i++;
	}
	return 0;
}