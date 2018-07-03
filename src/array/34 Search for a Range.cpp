/*
Given an array of integers nums sorted in ascending order, find the starting and
ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
#include <vector>
using namespace std;
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) {
      return {-1, -1};
    }
    int lo = 0;
    int hi = nums.size() - 1;
    int x = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (nums[mid] == target && (mid == 0 || nums[mid - 1] != target)) {
        x = mid;
        break;
      }
      if (nums[mid] >= target) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    lo = 0;
    hi = nums.size() - 1;
    int y = -1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (nums[mid] == target &&
          (mid == nums.size() - 1 || nums[mid + 1] != target)) {
        y = mid;
        break;
      }
      if (nums[mid] > target) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    }
    return {x, y};
  }
};