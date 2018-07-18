/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/
class Solution {
public:
    int numTrees(int n) {
      if (n == 1) return 1;
      vector<int> mem(n + 1, 0);
      vector<int> prev(n + 1, 0);
      prev[1] = 1;
      for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= i + 1; ++j) {
          int x = 0;
          for (int k = j - 1; k <= i; ++k) {
            x += prev[k];
          }
          mem[j] = x;
        }
        prev = mem;
      }
      int res = 0;
      for (int i = 1; i <= n; ++i) {
        res += mem[i];
      }
      return res;
    }
};

class Solution {
public:
    int numTrees(int n) {
      vector<int> G(n + 1, 0);
      G[0] = 1;
      G[1] = 1;
      for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
          G[i] += G[j - 1] * G[i - j];
        }
      }
      return G[n];
    }
};