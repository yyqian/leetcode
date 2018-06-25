/*
Given n pairs of parentheses, write a function to generate all combinations of
well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

#include <stack>
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    helper(res, 0, "", n, n);
    return res;
  }

 private:
  void helper(vector<string> &res, int open, string trace, int leftRemain,
              int rightRemain) {
    if (leftRemain == 0 && rightRemain == 0) {
      res.push_back(trace);
      return;
    }
    if (open == 0) {
      helper(res, 1, trace + '(', leftRemain - 1, rightRemain);
    } else {
      if (leftRemain > 0) {
        helper(res, open + 1, trace + '(', leftRemain - 1, rightRemain);
      }
      helper(res, open - 1, trace + ')', leftRemain, rightRemain - 1);
    }
  }
};

class SolutionBest {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    helper(res, "", n, 0);
    return res;
  }

 private:
  void helper(vector<string> &res, string trace, int leftRemain, int toClose) {
    if (leftRemain == 0 && toClose == 0) {
      res.push_back(trace);
      return;
    }
    if (leftRemain > 0) {
      helper(res, trace + '(', leftRemain - 1, toClose + 1);
    }
    if (toClose > 0) {
      helper(res, trace + ')', leftRemain, toClose - 1);
    }
  }
};