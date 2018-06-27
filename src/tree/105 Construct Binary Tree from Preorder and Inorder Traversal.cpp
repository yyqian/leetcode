#include <algorithm>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeMy(vector<int>& preorder, vector<int>& inorder) {
  if (preorder.empty() || inorder.empty()) {
    return nullptr;
  }
  int root_val = preorder[0];
  int i = 0;
  for (; i < inorder.size(); ++i) {
    if (inorder[i] == root_val) {
      break;
    }
  }
  vector<int> left_preorder;
  vector<int> right_preorder;
  vector<int> left_inorder;
  vector<int> right_inorder;
  for (int j = 0; j < preorder.size(); j++) {
    if (j < i) {
      left_inorder.push_back(inorder[j]);
    } else if (j > i) {
      right_inorder.push_back(inorder[j]);
    }
    if (j > 0 && j <= i) {
      left_preorder.push_back(preorder[j]);
    } else if (j > i) {
      right_preorder.push_back(preorder[j]);
    }
  }
  TreeNode* root = new TreeNode(root_val);
  root->left = buildTree(left_preorder, left_inorder);
  root->right = buildTree(right_preorder, right_inorder);
  return root;
}

class Solution {
 public:
  TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int i, int j,
                   int n) {
    if (n == 0) {
      return nullptr;
    }
    int root_val = preorder[i];
    auto f = find(inorder.begin() + j, inorder.end(), root_val);
    int len = f - inorder.begin() - j;
    TreeNode* root = new TreeNode(root_val);
    root->left = helper(preorder, inorder, i + 1, j, len);
    root->right =
        helper(preorder, inorder, i + len + 1, j + len + 1, n - len - 1);
    return root;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return helper(preorder, inorder, 0, 0, inorder.size());
  }
};