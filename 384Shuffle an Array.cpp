/*
Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();
Subscribe to see which companies asked this question
*/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	Solution(vector<int> nums):v(nums) {

	}

	/** Resets the array to its original configuration and return it. */
	vector<int> reset() {
		return v;
	}

	/** Returns a random shuffling of the array. */
	vector<int> shuffle() {
		vector<int>tmp = v;
		for (int i = 0; i < v.size(); ++i){
			int j = rand() % (v.size());
			swap(tmp[i], tmp[j]);
		}
		return tmp;
	}
private:
	vector<int>v;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution obj = new Solution(nums);
* vector<int> param_1 = obj.reset();
* vector<int> param_2 = obj.shuffle();
*/