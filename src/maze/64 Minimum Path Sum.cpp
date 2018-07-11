/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      vector<vector<int>> sum(m, vector<int>(n, 0));
      for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
          if (i == m - 1 && j == n - 1) {
            sum[i][j] = grid[i][j];
          } else if (i == m - 1) {
            sum[i][j] = grid[i][j] + sum[i][j+1];
          } else if (j == n - 1) {
            sum[i][j] = grid[i][j] + sum[i+1][j];
          } else {
            sum[i][j] = grid[i][j] + min(sum[i+1][j], sum[i][j+1]);
          }
        }
      }
      return sum[0][0];
    }
};