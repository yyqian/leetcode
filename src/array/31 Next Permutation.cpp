/*
Implement next permutation, which rearranges numbers into the lexicographically
next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible
order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding
outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/
#include <vector>
using namespace std;
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() <= 1) {
      return;
    }
    int target = nums.size() - 2;
    while (true) {
      if (nums[target + 1] > nums[target]) {
        break;
      }
      target--;
      if (target == -1) {
        break;
      }
    }
    if (target == -1) {
      reverse(nums, 0, nums.size() - 1);
      return;
    }
    int idx1 = target + 1;
    while (idx1 < nums.size() && nums[idx1] > nums[target]) {
      idx1++;
    }
    idx1--;
    swap(nums, target, idx1);
    reverse(nums, target + 1, nums.size() - 1);
  }

 private:
  void swap(vector<int>& nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
  }
  void reverse(vector<int>& nums, int i, int j) {
    while (i < j) {
      swap(nums, i, j);
      i++;
      j--;
    }
  }
};