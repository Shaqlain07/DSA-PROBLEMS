int height(Node* root) {
    if(root==NULL) { //edge case
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    
    return 1+max(h1,h2);
}
class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        if(root==NULL) { //base case
            return true;
        }
        int hleft=height(root->left);
        int hright=height(root->right);
        
        int diff=abs(hright-hleft); //absolute value
        bool a;
        bool b;
        if(diff<=1) {
             a=isBalanced(root->left);
             b=isBalanced(root->right);
        }
        else {
            return false;
        }
        if(a && b) {
            return true;
        }
        return false;
    }
};
