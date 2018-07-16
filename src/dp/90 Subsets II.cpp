/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      vector<vector<int>> res(1, vector<int>());
      int i = 0;
      while (i < nums.size()) {
        int cnt = 1;
        for (int j = i + 1; j < nums.size(); ++j) {
          if (nums[j] == nums[i]) {
            cnt++;
          } else {
            break;
          }
        }
        int sz = res.size();
        for (int k = 0; k < sz; ++k) {
          for (int j = 1; j <= cnt; ++j) {
            vector<int> nw = res[k];
            for (int t = 0; t < j; ++t) {
              nw.push_back(nums[i]);
            }
            res.push_back(nw);
          }
        }
        i += cnt;
      }
      return res;
    }
};