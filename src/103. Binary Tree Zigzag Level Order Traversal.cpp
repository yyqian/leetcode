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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (nullptr == root) return res;
    stack<TreeNode *> *stk = new stack<TreeNode *>();
    stack<TreeNode *> *tmp = new stack<TreeNode *>();
    stk->push(root);
    bool rightToleft = false;
    while (!stk->empty()) {
      vector<int> lvl;
      while (!stk->empty()) {
        TreeNode *tp = stk->top();
        stk->pop();
        lvl.push_back(tp->val);
        if (rightToleft) {
          if (tp->right != nullptr) tmp->push(tp->right);
          if (tp->left != nullptr) tmp->push(tp->left);
        } else {
          if (tp->left != nullptr) tmp->push(tp->left);
          if (tp->right != nullptr) tmp->push(tp->right);
        }
      }
      rightToleft = !rightToleft;
      stack<TreeNode *> *xc = stk;
      stk = tmp;
      tmp = xc;
      res.push_back(lvl);
    }
    return res;
  }
};