/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.

*/

class Solution {
public:
    int sumNumbers(TreeNode* root) {
      if (!root) return 0;
      vector<int> path;
      int sum = 0;
      dfs(path, root, sum);
      return sum;
    }
    void dfs(vector<int> &path, TreeNode* root, int &sum) {
      if (root->left == nullptr && root->right == nullptr) {
        sum += root->val;
        int multip = 1;
        for (int i = path.size() - 1; i >= 0; --i) {
          multip *= 10;
          sum += multip * path[i];
        }
        return;
      }
      path.push_back(root->val);
      if (root->left) dfs(path, root->left, sum);
      if (root->right) dfs(path, root->right, sum);
      path.pop_back();
    }
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
      return recur(root, 0);
    }
    int recur(TreeNode* root, int accum) {
      if (!root) return 0;
      int next = accum * 10 + root->val;
      if (!root->left && !root->right) return next;
      return recur(root->left, next) + recur(root->right, next);
    }
};