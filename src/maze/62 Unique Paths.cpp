/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 7 x 3 grid. How many possible unique paths are there?

Note: m and n will be at most 100.

Example 1:

Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Right -> Down
2. Right -> Down -> Right
3. Down -> Right -> Right
Example 2:

Input: m = 7, n = 3
Output: 28
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>> mem(m);
      for (vector<int> &ele : mem) {
        ele = vector<int>(n, -1);
      }
      return pathMem(m, n, mem);
    }

    int pathMem(int m, int n, vector<vector<int>> &mem) {
      if (m <= 0 || n <= 0) {
        return 0;
      } else if (m == 1 || n == 1) {
        return 1;
      }
      if (mem[m - 1][n - 1] != -1) {
        return mem[m - 1][n - 1];
      }
      int res = pathMem(m - 1, n, mem) + pathMem(m, n - 1, mem);
      mem[m - 1][n - 1] = res;
      return res;
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
      vector<vector<int>> path(m, vector<int> (n, 1));
      for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            path[i][j] = path[i - 1][j] + path[i][j - 1];
        }
      }
      return path[m - 1][n - 1];
    }
};