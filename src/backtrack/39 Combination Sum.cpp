/*
Given a set of candidate numbers (candidates) (without duplicates) and a target
number (target), find all unique combinations in candidates where the candidate
numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of
times.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]
Example 2:

Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> result;
    vector<int> trace;
    sort(candidates.begin(), candidates.end());
    backtrack(result, candidates, trace, target, 0);
    return result;
  }

 private:
  void backtrack(vector<vector<int>> &res, vector<int> &candidates,
                 vector<int> &trace, int remain, int start) {
    if (remain < 0) {
      return;
    } else if (remain == 0) {
      res.push_back(trace);
      return;
    }
    for (int i = start; i < candidates.size(); ++i) {
      trace.push_back(candidates[i]);
      backtrack(res, candidates, trace, remain - candidates[i], i);
      trace.pop_back();
    }
  }
};