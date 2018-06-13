#include <deque>
#include <string>
#include <vector>

using namespace std;

/*
Given a string, find the length of the longest substring without repeating
characters. Examples: Given "abcabcbb", the answer is "abc", which the length
is 3. Given "bbbbb", the answer is "b", with the length of 1. Given "pwwkew",
the answer is "wke", with the length of 3. Note that the answer must be a
substring, "pwke" is a subsequence and not a substring.
*/

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }
    deque<char> pipe;
    int result = 1;
    for (int i = 0; i < s.size(); ++i) {
      char current = s.at(i);
      int j = 0;
      for (; j < pipe.size(); ++j) {
        if (pipe[j] == current) {
          break;
        }
      }
      if (j < pipe.size()) {
        for (int k = 0; k <= j; ++k) {
          pipe.pop_front();
        }
      }
      pipe.push_back(current);
      result = result > pipe.size() ? result : pipe.size();
    }
    return result;
  }
};

class SolutionBest {
 public:
  int lengthOfLongestSubstring(string s) {
    vector<int> dict(256, -1);
    int result = 0;
    int head = -1;
    for (int i = 0; i != s.size(); ++i) {
      head = max(head, dict[s[i]]);
      dict[s[i]] = i;
      result = max(result, i - head);
    }
    return result;
  }
};