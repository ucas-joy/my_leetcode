/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific
target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must 
be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> result;
		if (numbers.size() == 0) {
			return result;
		}
		if (numbers[0] > target) {
			return result;
		}
		int begin = 0;
		int end = numbers.size() - 1;
		while (begin <= end) {
			 if(numbers[begin] + numbers[end] < target){
				begin++;
			}else if(numbers[begin] + numbers[end] > target){
				end--;
			}else if(numbers[begin] + numbers[end] == target){
				result.push_back(begin+1);
				result.push_back(end+1);
				return result;
			}
		}
		return result;
	}
}; 
int main167()
{
	int a[4] = { -3, 3, 4, 90 };
	vector<int>num(a, a + 4);
	Solution sol;
	vector<int>res;
	res = sol.twoSum(num, 0);
	int i = 0;
	while(i < res.size())
	{
		cout << res[i] << endl;
		i++;
	}
	return 0;
}