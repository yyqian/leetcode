/*
Given a string containing digits from 2-9 inclusive, return all possible letter
combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given
below. Note that 1 does not map to any letters.

2:abc
3:def
4:ghi
5:jkl
6:mno
7:pqrs
8:tuv
9:wxyz

Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/
#include <string>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return vector<string>();
    }
    vector<string> keyboard = {"",    "",    "abc",  "def", "ghi",
                               "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> result;
    for (char c : keyboard[digits[0] - '0']) {
      string s(1, c);
      result.push_back(s);
    }
    for (int i = 1; i != digits.size(); ++i) {
      int num = digits[i] - '0';
      vector<string> temp;
      for (string s : result) {
        for (char c : keyboard[num]) {
          temp.push_back(s + c);
        }
      }
      result.swap(temp);
    }
    return result;
  }
};