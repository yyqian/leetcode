/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
  }

 private:
  TreeNode* helper(vector<int>& nums, int front, int back) {
    if (front > back) return nullptr;
    if (front == back) return new TreeNode(nums[front]);
    int mid = front + (back - front) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = helper(nums, front, mid - 1);
    root->right = helper(nums, mid + 1, back);
    return root;
  }
};