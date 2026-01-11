#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int value)
    {
        val = value;
        left = NULL;
        right = NULL;
    }
};
// this function returns root node
Node *buildtree()
{
    int val;
    cin >> val;
    if (val == -1)
    {
        return NULL; // node mt bnao nulll lga do
    }
    else
    {
        Node *root = new Node(val);
        // 1 case above line me maine kr diya
        root->left = buildtree();  // ye left subtree bna ke return kr dega
        root->right = buildtree(); // and ye right subtree return kr dega
        return root;               // finally completely tree bna hua wala root return kr do
    }
}

void preordertraversal(Node *root) // root node mangaya hai tarversal krne ke liye
{
    // base case->agar NULL node pr PAHUCHE to kuch nhi kr skte wapas aa jao
    if (root == NULL)
    {
        return;
    }
    // 1 case mera
    cout << root->val << " " << endl;
    // baaki recursion krega
    preordertraversal(root->left);  // left subtree tum dekh lena
    preordertraversal(root->right); // right subtree tum dekh lena
}

void innerordertraversal(Node *root)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    innerordertraversal(root->left);
    cout << root->val << " " << endl;

    innerordertraversal(root->right);
}

void postordertraversal(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    postordertraversal(root->left);
    postordertraversal(root->right);
    cout << root->val << " " << endl;
}

void leveltraversal(Node *root)
{
    if (root == NULL)
    { // root node hi null pr hai mtlb no element
        return;
    }

    queue<Node *> q;
    //push root and NULL to initialise -> ki yha se start krna hai
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        if (front == NULL)//yha NULL ka mtlb hai ki uss level ke saare node print ho chuke hain and next level ke saare node queue me store ho chuke hain
        {//agar front null ke equal haito nextline pr jao and if  queue empty nhi  hai to null insert kr do as marker ki yha vo wala level khtm hota hai
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->val << endl;
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
    }
}
int main()
{ // create a tree
  //  10 20 30 -1 -1 40 -1 -1 50 -1 60 -1 -1
    Node *root = buildtree();
    // cout << endl
    //      << "Printing preorder traversal" << endl;
    // preordertraversal(root);
    // cout << endl
    //      << "Printing inorder traversal" << endl;
    // innerordertraversal(root);
    // cout << endl
    //      << "Printing postorder traversal" << endl;
    // postordertraversal(root);

    cout << "Level Traversal" << endl;
    leveltraversal(root);
    return 0;
}