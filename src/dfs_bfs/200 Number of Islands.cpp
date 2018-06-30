#include <queue>
#include <vector>
using namespace std;
class Solution {
 public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.size() == 0 || grid[0].size() == 0) {
      return 0;
    }
    int islands = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == '1') {
          islands++;
          dfs(grid, i, j);
        }
      }
    }
    return islands;
  }

 private:
  void dfs(vector<vector<char>> &grid, int i, int j) {
    if (isWater(grid, i, j)) {
      return;
    }
    grid[i][j] = '0';
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
  }
  void bfs(vector<vector<char>> &grid, int i, int j) {
    queue<vector<int>> q;
    q.push({i, j});
    while (!q.empty()) {
      i = q.front()[0];
      j = q.front()[1];
      q.pop();
      if (isWater(grid, i, j)) {
        continue;
      }
      grid[i][j] = '0';
      q.push({i - 1, j});
      q.push({i + 1, j});
      q.push({i, j - 1});
      q.push({i, j + 1});
    }
  }
  bool isWater(vector<vector<char>> &grid, int i, int j) {
    return i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
           grid[i][j] != '1';
  }
};