#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.size() == 0)
			return 0;
		
		int i;
		for (i = 0; i <= citations.size(); ++i)
		{
			if (citations[i] >= citations.size() - i)
			{
				return  citations.size() - i;
				break;
			}
		}
		return 0;
	}
};

int main()
{
	int a[5] = { 3, 0, 6, 1, 5 };
	vector<int>b(a, a + 5);
	Solution sol;
	int i = sol.hIndex(b);
	cout << i << endl;
	return 0;
}
