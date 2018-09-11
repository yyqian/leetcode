vector<int> findOrder(vector<vector<int> &pairs) {
  vector<int> path;
  vector<bool> marked(pairs.size(), false);
  for (int i = 0; i < pairs.size(); ++i) {
    if (!marked[i]) dfs(pairs, path, marked, i);
  }
  return path;
}

void dfs(vector<vector<int> &pairs, vector<int> &path, vector<bool> &marked, int i) {
  marked[i] = true;
  for (int neighbor : pairs[i]) {
    if (!marked[i]) dfs(pairs, path, marked, neighbor);
  }
  path.push_back(i);
}