/*
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
#include <set>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    backtrack(result, path, used, nums);
    return result;
  }

 private:
  void backtrack(vector<vector<int>> &result, vector<int> &path,
                 vector<bool> &used, vector<int> &nums) {
    if (path.size() == nums.size()) {
      result.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (used[i]) {
        continue;
      }
      path.push_back(nums[i]);
      used[i] = true;
      backtrack(result, path, used, nums);
      used[i] = false;
      path.pop_back();
    }
  }
};