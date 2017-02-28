/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

Hint:

How many majority elements could it possibly have?
Do you have a better hint? Suggest it!
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;
class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int>v;
		set<int>s;
		if (nums.size() == 0)
			return v;
		int c1=0, c2=0, n1=0, n2=0;
		int len = nums.size();
		for (int i = 0; i < len; ++i){
			if (c1 == nums[i])	n1++;
			else if (c2 == nums[i]) n2++;
			else if (n1 == 0){
				c1 = nums[i];
				n1 = 1;
			}
			else if (n2 == 0){
				c2 = nums[i];
				n2 = 1;
			}else{
				--n1;--n2;
			}
		}
		n1 = 0;
		n2 = 0;
		for (int j = 0; j < len; ++j) {
			if (c1 == nums[j])
				n1++;
			if (c2 == nums[j])
				n2++;
		}
		if (n1 > len/3) s.insert(c1);
		if (n2 > len/3) s.insert(c2);
		v.assign(s.begin(), s.end());
		return v;
	}
};

int main()
{
	int a[7] = {0,0 ,1,1,1,1,1};
	Solution sol;
	vector<int>b(a, a + 7);
	vector<int>c;
	c = sol.majorityElement(b);
	int i = 0;
	int len = c.size();
	while(i < len){
		cout << c[i] << endl;
		i++;
	}
	return 0;
}