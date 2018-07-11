/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/
class Solution {
public:
    string addBinary(string a, string b) {
      int len = max(a.size(), b.size());
      int i = a.size() - 1;
      int j = b.size() - 1;
      int carry = 0;
      string res;
      for (int k = 0; k < len; ++k) {
        int sum = carry;
        if (i >= 0) {
          sum += a[i--] - '0';
        }
        if (j >= 0) {
          sum += b[j--] - '0';
        }
        carry = sum / 2;
        res = (char)(sum % 2 + '0') + res;
      }
      if (carry != 0) {
        res = '1' + res;
      }
      return res;
    }
};