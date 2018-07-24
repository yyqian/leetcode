/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.
*/
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
    bool isBalanced(TreeNode* root) {
      int d;
      return helper(root, d);
    }
private:
    bool helper(TreeNode* root, int& r_depth) {
      if (!root) {
        r_depth = 0;
        return true;
      }
      int left_depth = 0;
      int right_depth = 0;
      if (!helper(root->left, left_depth)) return false;
      if (!helper(root->right, right_depth)) return false;
      int diff = left_depth - right_depth;
      if (diff < -1 || diff > 1) return false;
      r_depth = max(left_depth, right_depth) + 1;
      return true;
    }
};