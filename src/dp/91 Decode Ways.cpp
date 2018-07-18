/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/
class Solution {
public:
    int numDecodings(string s) {
      if (s.empty() || s[0] == '0') {
        return 0;
      } else if (s.size() == 1) {
        return 1;
      } else if (s.size() == 2) {
        int v = 10 * (s[0] - '0') + s[1] - '0';
        if (v >= 10 && v <= 26) {
          return s[1] == '0' ? 1 : 2;
        } else {
          return s[1] == '0' ? 0 : 1;
        }
      }
      int res = 0;
      if (s[0] != '0') {
        res += numDecodings(s.substr(1));
      }
      int v = 10 * (s[0] - '0') + s[1] - '0';
      if (v <= 26) {
        res += numDecodings(s.substr(2));
      }
      return res;
    }
};

class Solution {
public:
  int numDecodings(string s) {
    vector<int> mem(s.size() + 1, 0);
    mem[s.size()] = 1;
    mem[s.size() - 1] = s[s.size() - 1] == '0' ? 0 : 1;
    for (int i = s.size() - 2; i >= 0; --i) {
      if (s[i] == '0') continue;
      int v = 10 * (s[i] - '0') + s[i + 1] - '0';
      if (v <= 26) {
        mem[i] = mem[i + 1] + mem[i + 2];
      } else {
        mem[i] = mem[i + 1];
      }
    }
    return mem[0];
  }
};