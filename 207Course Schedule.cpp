/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.

click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. 
If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
Subscribe to see which companies asked this question

Show Tags
Show Similar Problems

*/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<vector<int>> pre(numCourses);
		int N = prerequisites.size();
		vector<int> inDegree(numCourses, 0);
		for (int i = 0; i<N; ++i) {
			auto p = prerequisites[i];
			inDegree[p.first]++;
			pre[p.second].push_back(p.first);
		}
		queue<int> que;
		for (int i = 0; i<numCourses; ++i) {
			if (inDegree[i] == 0) que.push(i);
		}
		int count = 0;
		while (!que.empty()) {
			int acc = que.front();
			que.pop();
			++count;
			for (auto st : pre[acc]) {
				if (inDegree[st] == 1) {
					que.push(st);
				}
				inDegree[st]--;
			}
		}
		return count == numCourses;
	}
		
};
int main207()
{
	vector<pair<int, int>> p = { {0,1} ,{1,0} };
	Solution sol;
	bool is = sol.canFinish(2,p);
	cout << is << endl;
	return 0;
}
/*
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> degrees = compute_indegree(graph);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++)
                if (!degrees[j]) break;
            if (j == numCourses) return false;
            degrees[j] = -1;
            for (int neigh : graph[j])
                degrees[neigh]--;
        }
        return true;
    }
private:
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites)
            graph[pre.second].insert(pre.first);
        return graph;
    }
    vector<int> compute_indegree(vector<unordered_set<int>>& graph) {
        vector<int> degrees(graph.size(), 0);
        for (auto neighbors : graph)
            for (int neigh : neighbors)
                degrees[neigh]++;
        return degrees;
    }
}; 
*/