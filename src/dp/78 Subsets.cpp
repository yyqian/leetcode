/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> res(1, vector<int>());
      for (int j = 0; j < nums.size(); ++j) {
        int n = nums[j];
        int sz = res.size();
        for (int i = 0; i < sz; ++i) {
          vector<int> ele = res[i];
          ele.push_back(n);
          res.push_back(ele);
        }
      }
      return res;
    }
};