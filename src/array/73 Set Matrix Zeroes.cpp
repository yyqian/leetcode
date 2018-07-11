/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input:
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output:
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input:
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output:
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int i = -1;
      int j = -1;
      for (int x = 0; x < matrix.size(); ++x) {
        for (int y = 0; y < matrix[0].size(); ++y) {
          if (matrix[x][y] == 0) {
            if (i == -1) {
              i = x;
              j = y;
            } else {
              matrix[i][y] = 0;
              matrix[x][j] = 0;
            }
          }
        }
      }
      if (i == -1) return;
      for (int k = 0; k < matrix.size(); ++k) {
        if (matrix[k][j] == 0 && k != i) {
          for (int l = 0; l < matrix[0].size(); ++l) {
            matrix[k][l] = 0;
          }
        }
      }
      for (int k = 0; k < matrix[0].size(); ++k) {
        if (matrix[i][k] == 0 && k != j) {
          for (int l = 0; l < matrix.size(); ++l) {
            matrix[l][k] = 0;
          }
        }
      }
      for (int k = 0; k < matrix.size(); ++k) {
        matrix[k][j] = 0;
      }
      for (int k = 0; k < matrix[0].size(); ++k) {
        matrix[i][k] = 0;
      }
    }
};