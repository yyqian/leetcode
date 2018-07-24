/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> res;
      if (numRows <= 0) return res;
      res.push_back(vector<int> (1, 1));
      for (int i = 2; i <= numRows; ++i) {
        const vector<int> &last = res.back();
        vector<int> next;
        next.push_back(1);
        for (int j = 1; j < last.size(); ++j) {
          next.push_back(last[j - 1] + last[j]);
        }
        next.push_back(1);
        res.push_back(next);
      }
      return res;
    }
};