/*
Write an efficient algorithm that searches for a value in an m x n matrix. This
matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous
row. Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false
*/
#include <vector>
using namespace std;
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
      return false;
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int start = 0;
    int end = m * n - 1;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      int midVal = matrix[mid / n][mid % n];
      if (midVal == target) {
        return true;
      } else if (midVal > target) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
    return false;
  }
};