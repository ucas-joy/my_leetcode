/*
There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach
the end of the list.

Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left, until a single number remains.

Find the last number that remains starting with a list of length n.

Example:

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
using namespace std;
/*class Solution {
public:
	int lastRemaining(int n) {
		if (n == 1)
			return 1;
		vector<int>nums;
		for (int i = 1; i <= n; ++i){
			nums.push_back(i);
		}
		vector<int>::iterator it;
		while (1){
			for (it = nums.begin(); it != nums.end(); ++it){
				if (nums.size() == 1){
					return nums[0];
					break;
				}
				it = nums.erase(it);
				if (it == nums.end())
					break;
			}
			reverse(nums.begin(), nums.end());
		}
		
	}*/
class Solution {
public:
	int lastRemaining(int n) {
		return f(n);
		}
	int f(int n) { //´Ó×óÍùÓÒ
		if (n == 1) return 1;
		if (n == 2) return 2;
		if (n & 1 == 1) {
			return 2 * g((n - 1) / 2); //ÆæÊı
		}
		else {
			return 2 * g(n / 2);//Å¼Êı
		}
	}
	int g(int n) { //´ÓÓÒÍù×ó
		if (n == 1) return 1;
		if (n == 2) return 1;
		if (n & 1 == 1) {
			return 2 * f((n - 1) / 2); //ÆæÊı
		}
		else {
			return 2 * f(n / 2) - 1;//Å¼Êı
		}
	}

};
int main390()
{
	int n = 5;
	Solution sol;
	int m = sol.lastRemaining(n);
	cout << m << endl;
	return 0;
}