/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int minDiff = INT_MAX;
  TreeNode *prev;
  int getMinimumDifference(TreeNode *root) {
    dfs(root);
    return minDiff;
  }
  void dfs(TreeNode *root) {
    if (root == NULL)
      return;
    dfs(root->left);
    if (prev) {
      minDiff = min(minDiff, abs(prev->val - root->val));
    }
    prev = root;
    dfs(root->right);
  }
};
