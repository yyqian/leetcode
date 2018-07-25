/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/
class Solution {
public:
    void flatten(TreeNode* root) {
      if (!root) return;
      flatten(root->right);
      flatten(root->left);
      root->left = nullptr;
      root->right = prev;
      prev = root;
    }

private:
    TreeNode* prev;
};