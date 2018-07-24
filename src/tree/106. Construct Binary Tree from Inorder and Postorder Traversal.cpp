/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }

private:
    TreeNode* helper(vector<int>& inorder, int i, int j, vector<int>& postorder, int ii, int jj) {
      if (i >= j || ii >= jj) {
        return nullptr;
      }
      int root_val = postorder[jj - 1];
      auto midIt = find(inorder.begin() + i, inorder.end() + j, root_val);
      int dis = midIt - inorder.begin() - i;
      TreeNode* root = new TreeNode(root_val);
      root->left = helper(inorder, i, i + dis, postorder, ii, ii + dis);
      root->right = helper(inorder, i + dis + 1, j, postorder, ii + dis, jj - 1);
      return root;
    }
};