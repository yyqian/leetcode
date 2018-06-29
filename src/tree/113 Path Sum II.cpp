/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum
equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> result;
    vector<int> path;
    helper(result, path, root, sum);
    return result;
  }

 private:
  void helper(vector<vector<int>> &result, vector<int> &path, TreeNode *root,
              int sum) {
    if (root == nullptr) {
      return;
    }
    int newSum = sum - root->val;
    path.push_back(root->val);
    if (newSum == 0 && root->left == nullptr && root->right == nullptr) {
      result.push_back(path);
      path.pop_back();
      return;
    }
    helper(result, path, root->left, newSum);
    helper(result, path, root->right, newSum);
    path.pop_back();
  }
};