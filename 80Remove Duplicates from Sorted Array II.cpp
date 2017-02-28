/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2)
			return nums.size();
		int len = nums.size();
		int tmpL = len;
		int tmpTime = 0;
		int times = 1;
		vector<int>::iterator slow, fast;
		for (slow = nums.begin(), fast = nums.begin()+1; slow!=nums.end() && fast !=nums.end();) {
			 while(fast != nums.end()&&(*slow == *fast)){
				times++;
				fast++;
				
			}
			 fast--;
			 tmpTime = times;
			 while (tmpTime > 2){
				 fast = nums.erase(fast);
				 fast--;
				 tmpTime--;
			 }
			slow = ++fast;
	        times = 1;
			fast++;	
		}
		return nums.size();
	}
};
int main80()
{
	int a[6] = { 1,1,1,2,2,3 };
	vector<int>b(a, a + 6);
	Solution sol;
	int i = sol.removeDuplicates(b);
	cout << i << endl;
	return 0;
}
