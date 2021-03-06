/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to
you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index,
otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
#include <vector>
using namespace std;
class Solution {
 public:
  int search(vector<int> &nums, int target) {
    if (nums.empty()) {
      return -1;
    }
    return helper(nums, target, 0, nums.size() - 1);
  }

 private:
  int helper(vector<int> &nums, int target, int start, int end) {
    if (start == end) {
      return target == nums[start] ? start : -1;
    }
    if (nums[start] < nums[end]) {
      if (target < nums[start] || nums[end] < target) {
        return -1;
      }
      while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] > target) {
          end = mid - 1;
        } else if (nums[mid] < target) {
          start = mid + 1;
        } else {
          return mid;
        }
      }
      return -1;
    } else {
      int mid = start + (end - start) / 2;
      int res = helper(nums, target, start, mid);
      if (res == -1) {
        return helper(nums, target, mid + 1, end);
      } else {
        return res;
      }
    }
  }
};

class Solution {
 public:
  int search(vector<int> &nums, int target) {
    if (nums.empty()) {
      return -1;
    }
    int lo = 0;
    int hi = nums.size() - 1;
    while (lo <= hi) {
      int mid = lo + (hi - lo) / 2;
      if (nums[mid] == target) {
        return mid;
      }
      if (nums[lo] <= nums[mid]) {
        if (nums[mid] > target && nums[lo] <= target) {
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      } else {
        if (nums[mid] < target && nums[hi] >= target) {
          lo = mid + 1;
        } else {
          hi = mid - 1;
        }
      }
    }
    return -1;
  }
};