/*
Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a subsequence ai, aj, ak such that i < j < k and ai < ak < aj.
Design an algorithm that takes a list of n numbers as input and checks whether there is a 132 pattern in the list.

Note: n will be less than 15,000.

Example 1:
Input: [1, 2, 3, 4]

Output: False

Explanation: There is no 132 pattern in the sequence.
Example 2:
Input: [3, 1, 4, 2]

Output: True

Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:
Input: [-1, 3, 2, 0]

Output: True

Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
Subscribe to see which companies asked this question

Show Tags

*/
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
class Solution {
public:
	//  i < j < k 
	//  ai < ak < aj
	bool find132pattern(vector<int>& nums) {
		if (nums.size() <= 2)
			return false;
		int n = nums.size();
		int Min = nums[0];
		for (int i = 1; i < n; ++i)
		{
			Min = min(Min, nums[i - 1]);
			if (Min >= nums[i])
				continue;
			for (int j = i + 1; j < n; ++j)
			{
				if (nums[j] < nums[i] && nums[j] > Min)
					return true;
			}

		}
		return false;
	}
};

int main()
{
	vector<int> a = { 3,1,4,2 };
	Solution sol;
	bool f = sol.find132pattern(a);
	cout << f << endl;
	return 0;
}