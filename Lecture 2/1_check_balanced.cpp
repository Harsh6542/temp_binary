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
class Solution
{
public:
    int getheight(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int l = getheight(root->left) + 1;
        int r = getheight(root->right) + 1;
        return max(l, r);
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true; // root nulll pr hai mtlb vo node balanced hai
        }

        int leftAns = getheight(root->left);
        int rightAns = getheight(root->right);
        int diff = abs(leftAns - rightAns);
        if (diff > 1)
        {
            return false; // current Node balanced nhi hai
        }
        else
        {
            // current node balanced hai ab baaki lrft and right me check kr lo
            bool leftwala = isBalanced(root->left);
            bool rightwala = isBalanced(root->right);
            if (leftwala == true && rightwala == true)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
};