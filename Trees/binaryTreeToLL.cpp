class Solution
{
    public:
     Node* prev=NULL;
    void flatten(Node *root)
    {
        //code here
        if(root==NULL) {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->left=NULL;
        root->right=prev;
        prev=root;
        
    }
};
