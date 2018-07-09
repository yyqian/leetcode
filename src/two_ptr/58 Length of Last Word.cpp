/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Input: "Hello World"
Output: 5
*/
class Solution {
public:
  int lengthOfLastWord(string s) {
    int hi = s.size() - 1;
    for (; hi >= 0; --hi) {
      if (s[hi] != ' ' && (hi == s.size() - 1 || s[hi + 1] == ' ')) break;
    }
    int lo = hi;
    for (; lo >= 0; --lo) {
      if (s[lo] != ' ' && (lo == 0 || s[lo - 1] == ' ')) break;
    }
    if (hi < 0) {
      return 0;
    }
    return hi - lo + 1;
  }
};