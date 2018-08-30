/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> freq;
      for (int n : nums) {
        freq[n]++;
      }
      vector<vector<int>> bucket(nums.size() + 1);
      for (auto f : freq) {
        bucket[f.second].push_back(f.first);
      }
      vector<int> res;
      int cnt = 0;
      for (int i = bucket.size() - 1; i >= 1; --i) {
        if (!bucket[i].empty()) {
          for (int x : bucket[i]) {
            res.push_back(x);
            cnt++;
            if (cnt == k) {
              return res;
            }
          }
        }
      }
      return res;
    }
};