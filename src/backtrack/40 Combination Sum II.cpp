#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
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
      if (i > start && candidates[i] == candidates[i - 1]) {
        continue;
      }
      trace.push_back(candidates[i]);
      backtrack(res, candidates, trace, remain - candidates[i], i + 1);
      trace.pop_back();
    }
  }
};