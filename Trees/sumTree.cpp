class Solution
{
    public:
    int solve(Node* root,bool &flag) {//for checking sum
        
        if(root==NULL) {//edge case
            return 0;
        }
        //base case
        if( root->left==NULL && root->right==NULL) {
            return root->data;
        }
        int l=solve(root->left,flag);
        int r=solve(root->right,flag);
        
        if(root->data!=l+r) {
            flag=false;
            return 0;
        }
        return root->data+l+r;
        
        
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         //edge case
         if(root==NULL) {
             return true;
         }
         bool flag=true;//initialised as true and we will check for false
         int r=solve(root,flag);
         return flag;
    }
};
