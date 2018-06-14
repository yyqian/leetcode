/*
Given a string s, find the longest palindromic substring in s.
You may assume that the maximum length of s is 1000.
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:
Input: "cbbd"
Output: "bb"
*/

#include <string>

using namespace std;

class SolutionDP {
 public:
  string longestPalindrome(string s) {
    if (s.size() <= 1) {
      return s;
    }
    if (s.front() == s.back()) {
      string sub = s.substr(1, s.size() - 2);
      string inner = longestPalindrome(sub);
      if (sub.size() == inner.size()) {
        return s;
      }
    }
    string left = longestPalindrome(s.substr(0, s.size() - 1));
    string right = longestPalindrome(s.substr(1, s.size() - 1));
    return left.size() > right.size() ? left : right;
  }
};

// DP