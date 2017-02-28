/*
Equations are given in the format A / B = k, where A and B are variables represented as strings, 
and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0.
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries ,
where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

Subscribe to see which companies asked this question
*/
#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<string>
using namespace std;
class Solution {
public:
	unordered_map<string, vector<pair<string, double>>>children;
	pair<bool, double>search(string &a, string &b, unordered_set<string>&visited, double val)
	{//如果a没有访问过，将a标记为访问，然后开始遍历图
		if (visited.count(a) == 0) {
			visited.insert(a);
			for (auto p : children[a]) {
				double temp = val *p.second;
				if (p.first == b) { return make_pair(true, temp); }
				auto result = search(p.first, b, visited, temp);
				if (result.first) { return result; };
			}
		}
		return make_pair(false, -1.0);
	}
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		vector<double> ans;
		for (int i = 0; i < equations.size(); i++) {
			children[equations[i].first].push_back(make_pair(equations[i].second, values[i]));      // build graph list a->b
			children[equations[i].second].push_back(make_pair(equations[i].first, 1.0 / values[i]));// build graph list b->a
		}
		for (auto p : queries) {
			unordered_set<string> visited;                                                          // to record visited nodes
																									// p.first == p.second is special case
			ans.push_back(p.first == p.second && children.count(p.first) ? 1.0 : search(p.first, p.second, visited, 1.0).second);
		}
		return ans;
	}
};
int main399()
{
	vector<pair<string, string>> equations = { {"a", "b" }, { "b", "c" } };
	vector<double>values = { 2.0, 3.0 };
	vector<pair<string, string>>queries = { {"a", "c"},{"b", "a"},{"a", "e"},{"a", "a"},{"x", "x" } };
	Solution sol;
	vector<double>res = sol.calcEquation(equations, values, queries);
	
//	for (int i = 0; i < res.size(); ++i){
//		cout << res[i] << " ";
//	}
	cout << endl;
	return 0;
}