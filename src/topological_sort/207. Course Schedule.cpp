/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
Note:

The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
      vector<unordered_set<int>> graph = makeGraph(numCourses, prerequisites);
      vector<bool> visited(numCourses, false);
      vector<bool> onpath(numCourses, false);
      for (int i = 0; i < numCourses; ++i) {
        if (dfs(graph, i, visited, onpath)) return false;
      }
      return true;
    }
private:
    vector<unordered_set<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
      vector<unordered_set<int>> graph(numCourses);
      for (auto pre : prerequisites) {
        graph[pre.second].insert(pre.first);
      }
      return graph;
    }
    bool dfs(vector<unordered_set<int>> &graph, int i, vector<bool> &visited, vector<bool> &onpath) {
      if (onpath[i]) {
        return true;
      }
      if (visited[i]) {
        return false;
      }
      visited[i] = true;
      onpath[i] = true;
      for (int x : graph[i]) {
        if (dfs(graph, x, visited, onpath)) return true;
      }
      onpath[i] = false;
      return false;
    }
};

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
      List<Set<Integer>> graph = makeGraph(numCourses, prerequisites);
      List<Boolean> visited = new ArrayList<>();
      List<Boolean> onpath = new ArrayList<>();
      for (int i = 0; i < numCourses; ++i) {
        visited.add(false);
        onpath.add(false);
      }
      for (int i = 0; i < numCourses; ++i) {
        if (dfs(graph, i, visited, onpath)) return false;
      }
      return true;
    }
    private List<Set<Integer>> makeGraph(int numCourses, int[][] prerequisites) {
      List<Set<Integer>> graph = new ArrayList<>();
      for (int i = 0; i < numCourses; ++i) {
        graph.add(new HashSet<>());
      }
      for (int[] pre : prerequisites) {
        graph.get(pre[1]).add(pre[0]);
      }
      return graph;
    }
    private boolean dfs(List<Set<Integer>> graph, int i, List<Boolean> visited, List<Boolean> onpath) {
      if (onpath.get(i)) return true;
      if (visited.get(i)) return false;
      visited.set(i, true);
      onpath.set(i, true);
      for (int x : graph.get(i)) {
        if (dfs(graph, x, visited, onpath)) return true;
      }
      onpath.set(i, false);
      return false;
    }
}