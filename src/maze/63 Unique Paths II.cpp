/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?



An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:

Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      if (obstacleGrid.front().front() == 1 || obstacleGrid.back().back() == 1) {
        return 0;
      }
      int count = 0;
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      vector<int> x(1, 0);
      vector<int> y(1, 0);
      while (!x.empty()) {
        int i = x.back();
        int j = y.back();
        x.pop_back();
        y.pop_back();
        if (i == m - 1 && j == n - 1) {
          ++count;
        } else {
          if (i < m - 1 && obstacleGrid[i+1][j] != 1) {
            x.push_back(i + 1);
            y.push_back(j);
          }
          if (j < n - 1 && obstacleGrid[i][j+1] != 1) {
            x.push_back(i);
            y.push_back(j + 1);
          }
        }
      }
      return count;
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      vector<vector<int>> path(m+1, vector<int>(n+1, 0));
      path[m][n - 1] = 1;
      for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
          if (obstacleGrid[i][j] != 1) {
            path[i][j] = path[i+1][j] + path[i][j+1];
          }
        }
      }
      return path[0][0];
    }
};