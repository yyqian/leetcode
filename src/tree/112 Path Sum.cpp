struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
      return false;
    }
    int target = sum - root->val;
    if (root->left == nullptr && root->right == nullptr && target == 0) {
      return true;
    }
    return hasPathSum(root->left, target) || hasPathSum(root->right, target);
  }
};