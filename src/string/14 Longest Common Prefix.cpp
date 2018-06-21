/*
Write a function to find the longest common prefix string amongst an array of
strings.

If there is no common prefix, return an empty string "".

Example 1:

Input: ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
Note:

All given inputs are in lowercase letters a-z.
*/
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string res;
    int i = 0;
    int n = strs.size();
    if (n == 0) {
      return "";
    }
    char c = 'a';
    while (true) {
      for (int j = 0; j < n; ++j) {
        if (i >= strs[j].size()) {
          return res;
        }
        char curr = strs[j][i];
        if (j == 0) {
          c = curr;
        } else {
          if (c != curr) {
            return res;
          }
        }
      }
      res += c;
      ++i;
    }
    return res;
  }
};

class SolutionBetter {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    if (n == 0) {
      return "";
    }
    int m = strs[0].size();
    for (int i = 0; i < m; ++i) {
      char c = strs[0][i];
      for (int j = 1; j < n; ++j) {
        if (i == strs[j].size() || strs[j][i] != c) {
          return strs[0].substr(0, i);
        }
      }
    }
    return strs[0];
  }
};