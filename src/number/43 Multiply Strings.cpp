/*
Given two non-negative integers num1 and num2 represented as strings, return the
product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to
integer directly.
*/
#include <string>
using namespace std;
class Solution {
 public:
  string multiply(string num1, string num2) {
    string result(num1.size() + num2.size(), '0');
    for (int i = num1.size() - 1; i >= 0; --i) {
      int carry = 0;
      for (int j = num2.size() - 1; j >= 0; --j) {
        int tmp = (num1[i] - '0') * (num2[j] - '0') +
                  (result[i + j + 1] - '0') + carry;
        result[i + j + 1] = tmp % 10 + '0';
        carry = tmp / 10;
      }
      result[i] += carry;
    }
    int i = 0;
    for (; i < result.size(); ++i) {
      if (result[i] != '0') {
        break;
      }
    }
    result = result.substr(i);
    return result.empty() ? "0" : result;
  }
};