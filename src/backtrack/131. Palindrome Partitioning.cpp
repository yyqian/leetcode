/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Example:

Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
      vector<vector<string>> res;
      vector<string> path;
      dfs(res, path, s, 0);
      return res;
    }
private:
    void dfs(vector<vector<string>> &res, vector<string> &path, string &s, int idx) {
      if (idx == s.size()) {
        res.push_back(path);
        return;
      }
      for (int i = idx; i < s.size(); ++i) {
        if (isPalindrome(s, idx, i)) {
          path.push_back(s.substr(idx, i - idx + 1));
          dfs(res, path, s, i + 1);
          path.pop_back();
        }
      }
    }
    bool isPalindrome(string &str, int lo, int hi) {
      while (lo < hi) {
        if (str[lo] != str[hi]) return false;
        ++lo;
        --hi;
      }
      return true;
    }
};