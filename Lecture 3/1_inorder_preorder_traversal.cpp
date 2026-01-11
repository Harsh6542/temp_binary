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

// Very IMP question  for interview revise MT
// still crystal clear nhi hai-> dry run kro mt

class Solution
{
public:
    int getindex(vector<int> &inorder, int element)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            if (inorder[i] == element)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode *solve(vector<int> &preorder, vector<int> &inorder,
                    int &preorderindex, int startind, int endindex)
    {
        if (preorderindex >= preorder.size())
        {
            return NULL;
        }
        if (startind > endindex)
        {
            return NULL;
        }
        int element = preorder[preorderindex];
        preorderindex++;
        TreeNode *root = new TreeNode(element);
        int elemindex = getindex(inorder, element);

        // left
        root->left = solve(preorder, inorder, preorderindex, startind, elemindex - 1);

        // right
        root->right = solve(preorder, inorder, preorderindex, elemindex + 1, endindex);
        // root return
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int preorderindex = 0;
        int startind = 0;
        int endindex = inorder.size() - 1;
        TreeNode *root =
            solve(preorder, inorder, preorderindex, startind, endindex);
        return root;
    }
};