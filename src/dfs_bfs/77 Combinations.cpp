/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/
class Solution {
public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    vector<int> path;
    dfs(res, n, k, path, 1, 0);
    return res;
  }
private:
  void dfs(vector<vector<int>> &res, int n, int k, vector<int> &path, int start, int depth) {
    if (depth == k) {
      res.push_back(path);
      return;
    }
    for (int i = start; i <= n; ++i) {
      path.push_back(i);
      dfs(res, n, k, path, i + 1, depth + 1);
      path.pop_back();
    }
  }
};