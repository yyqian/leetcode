/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
*/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
      vector<string> res;
      vector<string> path;
      helper(s, 0, path, res);
      return res;
    }

private:
  void helper(string &s, int head, vector<string> &path, vector<string> &res) {
    if (path.size() == 3) {
      if (is_valid(s, head, s.size() - head)) {
        string ele = path[0] + "." + path[1] + "." + path[2] + "." + s.substr(head);
        res.push_back(ele);
      }
      return;
    }
    for (int i = 1; i <= 3; ++i) {
    if (is_valid(s, head, i)) {
      path.push_back(s.substr(head, i));
      helper(s, head + i, path, res);
      path.pop_back();
    }
    }
  }
  bool is_valid(string &s, int start, int len) {
    if (len > 3 || len == 0 || start + len > s.size() || (len != 1 && s[start] == '0')) return false;
    int i = 0;
    int val = 0;
    while (i < len) {
      val = 10 * val + s[start + i] - '0';
      ++i;
    }
    return val <= 255;
  }
};