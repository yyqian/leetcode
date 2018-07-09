/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).
*/
// 先reverse, 再转置
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin(), matrix.end());
    int n = matrix.size();
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};