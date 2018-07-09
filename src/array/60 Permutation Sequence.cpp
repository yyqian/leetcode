/*
The set [1,2,3,...,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note:

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.
Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
*/

class Solution {
public:
    string getPermutation(int n, int k) {
        string res(n, '0');
        vector<int> factorial(n);
        vector<int> candidate(n);
        factorial[0] = 1;
        candidate[0] = 1;
        for (int i = 1; i < n; ++i) {
          factorial[i] = factorial[i - 1] * i;
          candidate[i] = i + 1;
        }
        k--;
        for (int i = n; i >= 1; --i) {
          int pick = k / factorial[i - 1];
          res[n - i] = '0' + candidate[pick];
          for (int j = pick; j < i - 1; ++j) {
            candidate[j] = candidate[j + 1];
          }
          k = k - pick * factorial[i - 1];
        }
        return res;
    }
};