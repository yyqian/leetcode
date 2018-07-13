/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> path;
      helper(path, root);
      return path;
    }
private:
    void helper(vector<int> &path, TreeNode* root) {
      if (nullptr == root) {
        return;
      }
      helper(path, root->left);
      path.push_back(root->val);
      helper(path, root->right);
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> path;
      vector<TreeNode*> stk;
      while (root != nullptr) {
        stk.push_back(root);
        root = root->left;
      }
      while (!stk.empty()) {
        TreeNode* tmp = stk.back();
        stk.pop_back();
        path.push_back(tmp->val);
        tmp = tmp->right;
        while (tmp != nullptr) {
          stk.push_back(tmp);
          tmp = tmp->left;
        }
      }
      return path;
    }
};