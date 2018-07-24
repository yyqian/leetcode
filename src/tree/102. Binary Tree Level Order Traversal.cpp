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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (nullptr == root) return res;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int sz = q.size();
      vector<int> lvl;
      for (int i = 0; i < sz; ++i) {
        TreeNode* current = q.front();
        q.pop();
        lvl.push_back(current->val);
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
      }
      res.push_back(lvl);
    }
    return res;
  }
};