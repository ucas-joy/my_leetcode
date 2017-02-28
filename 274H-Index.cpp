/*
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h 
citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had
received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the 
remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

Hint:

An easy approach is to sort the array first.
What are the possible values of h-index?
A faster approach is to use extra space.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.size() == 0)
			return 0;
		if (citations.size() == 1)
			return 1;
		sort(citations.begin(), citations.end());
		int i;
		for (i = 0; i <= citations.size(); ++i)
		{
			if (citations[i] >= citations.size() - i)
			{
				return  citations.size()-i;
				break;
			}
		}
		return 0;
	}
};

int main274()
{
	int a[5] = { 3, 0, 6, 1, 5 };
	vector<int>b(a, a + 5);
	Solution sol;
	int i = sol.hIndex(b);
	cout << i << endl;
	return 0;
}