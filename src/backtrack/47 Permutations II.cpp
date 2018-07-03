/*
Given a collection of numbers that might contain duplicates, return all possible
unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
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
      if (used[i] || (i > 0 && nums[i] == nums[i - 1] &&
                      !used[i - 1])) {  // 这个地方很难写
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