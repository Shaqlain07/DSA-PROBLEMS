class Solution
{
    public:
    //traversing inorder in binary tree
    void inorder(Node* root,vector<int> &v) {
        if(root==NULL) {
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        // Your code here
        vector<int> v;
        inorder(root,v);
        bool flag=false;
        
        if(is_sorted(v.begin(),v.end())) {
            flag=true;
        }
        return flag;
    }
};
