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
#include <algorithm>
  int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int l = maxDepth(root->left) + 1;
        int r = maxDepth(root->right) + 1;
        return max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int opt1 = maxDepth(root->left) + maxDepth(root->right);
        int opt2 = diameterOfBinaryTree(root->left);
        int opt3 = diameterOfBinaryTree(root->right);
        return max(opt1, max(opt2, opt3));
    }
};