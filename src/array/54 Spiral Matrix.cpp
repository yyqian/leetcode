/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> path;
    if (matrix.empty()) {
      return path;
    }
    helper(matrix, path, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
    return path;
  }
private:
  void helper(vector<vector<int>>& matrix, vector<int> &path, int i, int j, int m, int n) {
    if (i > m || j > n) {
      return;
    }
    if (i == m) {
      for (int k = j; k <= n; ++k) {
        path.push_back(matrix[i][k]);
      }
      return;
    }
    if (j == n) {
      for (int k = i; k <= m; ++k) {
        path.push_back(matrix[k][j]);
      }
      return;
    }
    for (int k = j; k < n; ++k) {
      path.push_back(matrix[i][k]);
    }
    for (int k = i; k < m; ++k) {
      path.push_back(matrix[k][n]);
    }
    for (int k = n; k > j; --k) {
      path.push_back(matrix[m][k]);
    }
    for (int k = m; k > i; --k) {
      path.push_back(matrix[k][j]);
    }
    helper(matrix, path, i + 1, j + 1, m - 1, n - 1);
  }
};