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
    void solve(TreeNode *root, int targetSum, vector<int> &temp,
               vector<vector<int>> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        targetSum -= root->val;
        temp.push_back(root->val);

        if (root->left == NULL && root->right == NULL)
        {
            if (targetSum == 0)
            {
                ans.push_back(temp);
                temp.pop_back();//necessary when passed by reference
                return;
            }
        }

        solve(root->left, targetSum, temp, ans);
        solve(root->right, targetSum, temp, ans);

        temp.pop_back();//necessary when passed by reference
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> temp;
        vector<vector<int>> ans;
        solve(root, targetSum, temp, ans);
        return ans;
    }
};