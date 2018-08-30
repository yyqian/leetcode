/*
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \
     3   1

Output: 7
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
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
    int rob(TreeNode* root) {
      unordered_map<TreeNode*, int> cache;
      return rob(root, cache);
    }
private:
    int rob(TreeNode* root, unordered_map<TreeNode*, int> &cache) {
      if (!root) return 0;
      if (cache.find(root) != cache.end()) return cache.find(root)->second;
      int case1 = rob(root->left, cache) + rob(root->right, cache);
      int case2 = root->val;
      if (root->left) case2 += rob(root->left->left, cache) + rob(root->left->right, cache);
      if (root->right) case2 += rob(root->right->left, cache) + rob(root->right->right, cache);
      int res = max(case1, case2);
      cache.insert({root, res});
      return res;
    }
};
