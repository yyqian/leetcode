/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of
rows like this: (you may want to display this pattern in a fixed font for better
legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number
of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
*/
#include <string>
#include <vector>
using namespace std;

// 用状态机，状态：row 和 column
class MySolution {
 public:
  string convert(string s, int numRows) {
    if (s.size() <= 2 || numRows == 1) {
      return s;
    }
    int n = (int)s.size();
    vector<int> i(n);
    vector<int> j(n);
    int k = 0;
    int l = 0;
    for (int t = 0; t != n; ++t) {
      i[t] = k;
      j[t] = l;
      if (l % (numRows - 1) == 0 && k != (numRows - 1)) {
        k++;
      } else {
        k--;
        l++;
      }
    }
    vector<string> strs(numRows);
    for (int t = 0; t != n; ++t) {
      strs[i[t]] += s[t];
    }
    string res;
    for (string ele : strs) {
      res += ele;
    }
    return res;
  }
};
// 用状态机，状态：row 和 direction
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    int row = 0;
    bool down = false;
    vector<string> strs(numRows);
    for (char c : s) {
      strs[row] += c;
      if (row == 0 || row == numRows - 1) {
        down = !down;
      }
      row += down ? 1 : -1;
    }
    string result;
    for (string ele : strs) {
      result += ele;
    }
    return result;
  }
};