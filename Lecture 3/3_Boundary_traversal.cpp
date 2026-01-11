/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
//very very imp for interview purposes
class Solution {
  public:
  void lefttree(Node *root,vector<int>&ans){
      if(root==NULL){
          return ;
      }
      if(root->left==NULL && root->right==NULL){
          return;
      }
      
      //agar upar ka kuch nhi hai to hm valid node pr hain
      //answer me push kr do
      ans.push_back(root->data);
      //abb baaki recursion se krwao
      if(root->left!=NULL){
          lefttree(root->left,ans);
          
      }else{
          lefttree(root->right,ans);
      }
      
      
  }
  void leafnode(Node *root,vector<int>&ans){
      if(root==NULL){
          return;
      }
      if(root->left==NULL && root->right==NULL){
          ans.push_back(root->data);
          return;
      }
      leafnode(root->left,ans);
      leafnode(root->right,ans);
  }
  void righttree(Node *root,vector<int>&ans){
      if(root==NULL){
          return;
      }
      if(root->left==NULL && root->right==NULL){
          return;
      }
      if(root->right!=NULL){
          righttree(root->right,ans);
      }else{
          righttree(root->left,ans);
      }
      //reverse order me push krna hai issliye recursive call ke baad likho
      ans.push_back(root->data);
  }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        
        vector<int>ans;
        if(root==NULL){
           return ans;
        }
       //root node ko push kiya vector me
        ans.push_back(root->data);
        //left tree 
        lefttree(root->left,ans);
        
        leafnode(root->left,ans);
        leafnode(root->right,ans);
        
    righttree(root->right,ans);
        return ans;
    }
};