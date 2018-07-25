/*
Given a binary tree

struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
Recursive approach is fine, implicit stack space does not count as extra space for this problem.
Example:

Given the following binary tree,

     1
   /  \
  2    3
 / \    \
4   5    7
After calling your function, the tree should look like:

     1 -> NULL
   /  \
  2 -> 3 -> NULL
 / \    \
4-> 5 -> 7 -> NULL
*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
      if (!root) return;
      queue<TreeLinkNode*> q;
      q.push(root);
      while(!q.empty()) {
        int sz = q.size();
        TreeLinkNode* prev = nullptr;
        for (int i = 0; i < sz; ++i) {
          TreeLinkNode *current = q.front();
          q.pop();
          if (prev) prev->next = current;
          if (current->left) q.push(current->left);
          if (current->right) q.push(current->right);
          prev = current;
        }
      }
    }
};
