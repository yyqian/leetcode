/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
Example 1:

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".
Example 2:

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
             Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false

*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
      return dfs(s, wordSet);
    }
private:
    bool dfs(string s, unordered_set<string>& wordSet) {
      if (s.empty()) {
        return true;
      }
      for (int i = s.size(); i >= 1; --i) {
        if (wordSet.find(s.substr(0, i)) != wordSet.end()) {
          if (dfs(s.substr(i), wordSet)) return true;
        }
      }
      return false;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
      vector<bool> dp(s.size() + 1, false);
      dp[0] = true;
      for (int i = 1; i <= s.size(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
          if (dp[j]) {
            string tmp = s.substr(j, i - j);
            if (wordSet.find(tmp) != wordSet.end()) {
              dp[i] = true;
              break;
            }
          }
        }
      }
      return dp[s.size()];
    }
};