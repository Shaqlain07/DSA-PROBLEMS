class Solution{
  public:
  
    
    //fn for inorder traversal to store in vector
    void inorder(Node* root,vector<int> &v) {
        if(root==NULL) {
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    void bst(Node* root,vector<int> v,int &i) {//changing the date by inorder traversal
        if(root==NULL) {
            return;
        }
        bst(root->left,v,i);
        root->data=v[i];
        i++;
        bst(root->right,v,i);
    }
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> v;
        inorder(root,v);
        sort(v.begin(),v.end());
        int i=0;
        bst(root,v,i);//to vector in bst
        
        return root;
        
    }
};
