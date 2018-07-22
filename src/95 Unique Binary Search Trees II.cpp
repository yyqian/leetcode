/*
Given an integer n, generate all structurally unique BST's (binary search trees)
that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
  vector<TreeNode*> generateTrees(int n) {
    if (n == 0) return vector<TreeNode*>();
    return helper(1, n);
  }

 private:
  vector<TreeNode*> helper(int start, int end) {
    if (start > end) {
      vector<TreeNode*> res;
      res.push_back(nullptr);
      return res;
    }
    if (start == end) {
      vector<TreeNode*> res;
      res.push_back(new TreeNode(start));
      return res;
    }
    vector<TreeNode*> res;
    for (int i = start; i <= end; ++i) {
      vector<TreeNode*> left = helper(start, i - 1);
      vector<TreeNode*> right = helper(i + 1, end);
      for (TreeNode* leftEle : left) {
        for (TreeNode* rightEle : right) {
          TreeNode* root = new TreeNode(i);
          root->left = leftEle;
          root->right = rightEle;
          res.push_back(root);
        }
      }
    }
    return res;
  }
};