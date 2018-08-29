/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished
             course 0. So the correct course order is [0,1] .
Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
             courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
             So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3] .
*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
      vector<int> res;
      vector<bool> onpath(numCourses, false);
      vector<bool> visited(numCourses, false);
      vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
      for (int i = 0; i < numCourses; ++i) {
        if (dfs(graph, onpath, visited, i, res)) return vector<int>();
      }
      reverse(res.begin(), res.end());
      return res;
    }
private:
    vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
      vector<unordered_set<int>> graph(numCourses);
      for (auto pre : prerequisites) {
        graph[pre.second].insert(pre.first);
      }
      return graph;
    }
    bool dfs(vector<unordered_set<int>> &graph, vector<bool> &onpath, vector<bool> &visited, int i, vector<int> &res) {
      if (onpath[i]) return true;
      if (visited[i]) return false;
      visited[i] = true;
      onpath[i] = true;
      for (auto x : graph[i]) {
        if (dfs(graph, onpath, visited, x, res)) return true;
      }
      onpath[i] = false;
      res.push_back(i);
      return false;
    }
};