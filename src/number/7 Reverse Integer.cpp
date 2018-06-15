/*
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within
the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this
problem, assume that your function returns 0 when the reversed integer
overflows.


 */
#include <climits>
class Solution {
 public:
  int reverse(int x) {
    if (x < 10 && x > -10) {
      return x;
    } else if (x == INT_MIN) {
      return 0;
    } else if (x < 0) {
      return -reverse(-x);
    }
    long result = 0;
    while (x != 0) {
      result = 10 * result + x % 10;
      x = x / 10;
    }
    return (result > INT_MAX || result < INT_MIN) ? 0 : (int)result;
  }
};
// 小心 overflow