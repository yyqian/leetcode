/*
Given an array nums of n integers and an integer target, find three integers in
nums such that the sum is closest to target. Return the sum of the three
integers. You may assume that each input would have exactly one solution.

Example:

Given array nums = [-1, 2, 1, -4], and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
#include <vector>
using namespace std;
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int closest = nums[0] + nums[1] + nums[2];
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
      int j = i + 1;
      int k = nums.size() - 1;
      while (j < k) {
        int current = nums[i] + nums[j] + nums[k];
        if (abs(current - target) < abs(closest - target)) {
          closest = current;
        }
        if (current > target) {
          k--;
        } else if (current < target) {
          j++;
        } else {
          return target;
        }
      }
    }
    return closest;
  }

 private:
  int abs(int x) { return x < 0 ? -x : x; }
};