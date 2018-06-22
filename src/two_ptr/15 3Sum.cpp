/*
Given an array nums of n integers, are there elements a, b, c in nums such that
a + b + c = 0? Find all unique triplets in the array which gives the sum of
zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/
#include <vector>
using namespace std;
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if (nums.size() < 3) {
      return result;
    }
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
      int target = -nums[i];
      int j = i + 1;
      int k = nums.size() - 1;
      while (j < k) {
        int sum = nums[j] + nums[k];
        if (sum == target) {
          int b = nums[j];
          int c = nums[k];
          result.push_back(vector<int>{nums[i], b, c});
          j++;
          k--;
          while (j < k && nums[j] == b) {
            j++;
          }
          while (j < k && nums[k] == c) {
            k--;
          }
        } else if (sum > target) {
          k--;
        } else {
          j++;
        }
      }
      while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
        i++;
      }
    }
    return result;
  }
};