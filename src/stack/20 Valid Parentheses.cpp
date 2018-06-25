/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true
*/

#include <stack>
#include <string>
using namespace std;
class Solution {
 public:
  bool isValid(string s) {
    stack<char> stk;
    for (char &c : s) {
      switch (c) {
        case '(':
        case '[':
        case '{':
          stk.push(c);
          break;
        case ')':
          if (stk.empty() || stk.top() != '(') {
            return false;
          } else if (stk.top() == '(') {
            stk.pop();
          }
          break;
        case ']':
          if (stk.empty() || stk.top() != '[') {
            return false;
          } else if (stk.top() == '[') {
            stk.pop();
          }
          break;
        case '}':
          if (stk.empty() || stk.top() != '{') {
            return false;
          } else if (stk.top() == '{') {
            stk.pop();
          }
          break;
      }
    }
    return stk.empty();
  }
};

// stack