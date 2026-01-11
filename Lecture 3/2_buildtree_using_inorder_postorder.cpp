/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 //interview important  revise MT
class Solution {
public:
int getindex(vector<int>& inorder,int element){
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==element){
            return i;
        }
    }
    return -1;
}
TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &postindex,int start, int end){
    if(postindex<0){
        return NULL;
    }
    if(start>end){
        return  NULL;
    }
    int element =postorder[postindex];
    postindex--;
    TreeNode* root=new TreeNode(element);
    
    int index =getindex(inorder,element);
    //right first
    root->right = solve(inorder,postorder,postindex,index+1,end);
    root->left =solve(inorder,postorder,postindex,start,index-1);
return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postindex =postorder.size()-1;
        int start =0;
        int end =inorder.size()-1;
        TreeNode* root =solve(inorder,postorder,postindex,start,end);
        return root;
    }
};