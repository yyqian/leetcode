/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:
Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.

Test case
[3,0,8,2,0,0,X]

mem: -1 unknown，0，bad，1 good
*/
class SolutionRecurMem {
public:
  bool canJump(vector<int>& nums) {
    vector<int> mem(nums.size(), -1);
    return helper(nums, 0, mem);
  }
private:
  bool helper(vector<int> &nums, int i, vector<int> &mem) {
    if (mem[i] == 1) {
      return true;
    } else if (mem[i] == 0) {
      return false;
    }
    int dist = nums.size() - i - 1;
    if (dist == 0 || dist <= nums[i]) {
      mem[i] = 1;
      return true;
    }
    for (int n = nums[i]; n >= 1; --n) {
      if (helper(nums, i + n, mem)) {
        mem[i] = 1;
        return true;
      }
    }
    mem[i] = 0;
    return false;
  }
};

class SolutionRecur {
public:
  bool canJump(vector<int>& nums) {
    return helper(nums, 0);
  }
private:
  bool helper(vector<int> &nums, int i) {
    int dist = nums.size() - i - 1;
    if (dist == 0 || dist <= nums[i]) {
      return true;
    }
    for (int n = nums[i]; n >= 1; --n) {
      if (helper(nums, i + n)) {
        return true;
      }
    }
    return false;
  }
};