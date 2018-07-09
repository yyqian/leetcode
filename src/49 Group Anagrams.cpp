/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {}

 private:
  string hash(string str) {
    vector<int> dict(26, 0);
    for (char c : str) {
      dict[c - 'a']++;
    }
    string res;
    for (int n : dict) {
      res = res + "#" + to_string(n);
    }
    return res;
  }
};