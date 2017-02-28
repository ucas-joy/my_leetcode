/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
Subscribe to see which companies asked this question
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;

class Solution {
public:
	typedef pair<char, int> PAIR;
	struct cmp {
	bool operator()(const PAIR& lhs, const PAIR& rhs) {
		return lhs.second < rhs.second;
	}
   };
	string frequencySort(string s) {
		if (s.length() <= 1)
			return  s;
		string res;
		map<char, long long int>mp;
		for (int i = 0; i < s.length(); ++i){
			mp[s[i]]++;
		}
		priority_queue<PAIR, vector<PAIR>, cmp>Q;
		for (auto x : mp){
			Q.push(x);
		}
		while (!Q.empty())
		{
			auto x = Q.top();
			res += string(x.second, x.first);
			Q.pop();
		}
		return res;
	}
};
int main()
{
	string s = "tree";
	Solution sol;
	string res = sol.frequencySort(s);
	cout << res << endl;
	return 0;
}