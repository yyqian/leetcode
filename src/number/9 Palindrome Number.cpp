/*
Determine whether an integer is a palindrome. An integer is a palindrome when it
reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes
121-. Therefore it is not a palindrome. Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    int copy = x;
    long res = 0;
    while (copy != 0) {
      res = res * 10 + copy % 10;
      copy /= 10;
    }
    return res == x;
  }
};

class SolutionBest {
 public:
  bool isPalindrome(int x) {
    if (x >= 0 && x <= 9) {
      return true;
    }
    if (x < 0 || x % 10 == 0) {
      return false;
    }
    int res = 0;
    while (x > res) {
      res = res * 10 + x % 10;
      x /= 10;
    }
    return res == x || x == (res / 10);
  }
};