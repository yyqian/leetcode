/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?

The idea is the same as the previous one without duplicates
1) everytime check if targe == nums[mid], if so, we find it.
2) otherwise, we check if the first half is in order (i.e. nums[left]<=nums[mid])
  and if so, go to step 3), otherwise, the second half is in order,   go to step 4)
3) check if target in the range of [left, mid-1] (i.e. nums[left]<=target < nums[mid]), if so, do search in the first half, i.e. right = mid-1; otherwise, search in the second half left = mid+1;
4)  check if target in the range of [mid+1, right] (i.e. nums[mid]<target <= nums[right]), if so, do search in the second half, i.e. left = mid+1; otherwise search in the first half right = mid-1;

The only difference is that due to the existence of duplicates, we can have nums[left] == nums[mid] and in that case,
the first half could be out of order (i.e. NOT in the ascending order, e.g. [3 1 2 3 3 3 3]) and we have to deal this
case separately. In that case, it is guaranteed that nums[right] also equals to nums[mid], so what we can do is to check
if nums[mid]== nums[left] == nums[right] before the original logic, and if so, we can move left and right both towards
the middle by 1. and repeat.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
      int lo = 0;
      int hi = nums.size() - 1;
      while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (target == nums[mid]) {
          return true;
        }
        if (nums[lo] < nums[mid]) {
          // left in order
          if (nums[lo] <= target && target < nums[mid]) {
            hi = mid - 1;
          } else {
            lo = mid + 1;
          }
        } else if (nums[lo] > nums[mid]) {
          // right in order
          if (nums[mid] < target && target <= nums[hi]) {
            lo = mid + 1;
          } else {
            hi = mid - 1;
          }
        } else {
          // 3123333, 3333123,3333412
          if (nums[mid] == nums[hi]) {
            lo++;
            hi--;
          } else {
            lo = mid + 1;
          }
        }
      }
      return false;
    }
};