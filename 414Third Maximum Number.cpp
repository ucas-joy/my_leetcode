/*
Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number.
The time complexity must be in O(n).

Example 1:
Input: [3, 2, 1]

Output: 1

Explanation: The third maximum is 1.
Example 2:
Input: [1, 2]

Output: 2

Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
Example 3:
Input: [2, 2, 3, 1]

Output: 1

Explanation: Note that the third maximum here means the third maximum distinct number.
Both numbers with value 2 are both considered as second maximum.
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

/*class Solution {
public:
	int thirdMax(vector<int>& nums) {
		
		if (nums.size() < 3){
			return nums[0] >= nums[1] ? nums[0] : nums[1];
		}
		int k = partition(nums, nums.size(), 0, nums.size() - 1);

		if (k == 2){
			return nums[k];
		}
		while (k!= 2){
			if (k < 2)
			{
				k = partition(nums, nums.size(), k + 1, nums.size() - 1);
				
			}
			else if(k > 2)
			{
				k = partition(nums, nums.size(), 0, k - 1);
			}
		}
		return nums[nums.size()-1-k];
	}
	int partition(vector<int>&nums, int n, int p, int r){
		int i, j;
		int x = nums[r];
		i = p - 1;
		for (j = p; j < r; ++j){
			if (nums[j] <= x){
				i++;
				swap(nums[i], nums[j]);
			}
		}
		swap(nums[i + 1], nums[r]);
		return i + 1;
	}
};*/
class Solution {
public:
int thirdMax(vector<int>& nums) {
	set<int> s;
	for (int num : nums) {
		s.insert(num);
		if (s.size() > 3) {
			s.erase(s.begin());
		}
	}
	return s.size() == 3 ? *s.begin() : *s.rbegin();
}

int main()
{
	//int a[15] = { 13,19 ,9,5,12,8,7,4,21,2,5,3,14,6,11};
	int b[6] = { 13,19,9,5,12 ,8};
	//int b[3] = { 3,2,1 };
	vector<int>c(b, b +3);
	Solution sol;
	int i;
	i = sol.thirdMax(c);
	cout << i << endl;
	return 0;
}